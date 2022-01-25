#include "DLLProcessor.h"


void * compileDLLSource(const uint8_t * source, size_t sourceSize)
{
    #define SOURCE_CODE_PATH "/Users/laptevaleksander/Documents/GitHub/Raymarcher/build/RAYMARCHING_C_COMPILABLE_SOURCE.c"
    #define DLL_PATH "/Users/laptevaleksander/Documents/GitHub/Raymarcher/build/RAYMARCHING_C_COMPILABLE_SOURCE.so"
    #define DLL_OBJECT_PATH "/Users/laptevaleksander/Documents/GitHub/Raymarcher/build/RAYMARCHING_C_COMPILABLE_SOURCE.o"
    #define RAYMARCHER_SOURCE_FOLDER_PATH "/Users/laptevaleksander/Documents/GitHub/Raymarcher/"

    FILE * sourceFile = fopen(SOURCE_CODE_PATH, "w");

    if(!sourceFile)
    {
        printf("ERROR: Unable to create "SOURCE_CODE_PATH" !\n");
        return NULL;
    };

    fwrite(source, sourceSize, 1, sourceFile);

    fclose(sourceFile);

    int compilationResult = system(
                                   "gcc "SOURCE_CODE_PATH" -o "DLL_OBJECT_PATH" -fPIC -c "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/Vec/Vec.h "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/Vec/Vec3/Vec3.h "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/Vec/Vec2/Vec2.h "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/Vec/Vec3/Vec3.c "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/Vec/Vec2/Vec2.c "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/RGB/RGB.h "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/RGB/RGB.c "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/SceneEnviroment/Camera.h "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/SceneEnviroment/SceneEnviroment.h "
                                   "-include"RAYMARCHER_SOURCE_FOLDER_PATH"/SceneEnviroment/SceneObjects.h "
                                   );

    if(compilationResult != 0)
    {
        printf("ERROR: CC finished with status code: %i\n", compilationResult);
        return NULL;
    };

    compilationResult = system(
                                   "gcc "DLL_OBJECT_PATH" -o "DLL_PATH" -shared"
                               );

    if(compilationResult != 0)
    {
        printf("ERROR: CC finished with status code: %i\n", compilationResult);
        return NULL;
    };

    void* dynlib = dlopen(DLL_PATH, RTLD_LAZY);
    if(!dynlib)
    {
        printf("ERROR: Unable to open DLL. Status code: %s\n", dlerror());
    };

    return dynlib;
};

void * extractSymbolFromDLL(void * dynlib, char * symbolName)
{
    void * create = dlsym(dynlib, symbolName);
    const char* dlsym_error=dlerror();
    if(dlsym_error != NULL)
    {
        printf("ERROR: Unable to find symbol \" %s \"\n Status code: %s\n", symbolName, dlsym_error);
    };

    return create;
};

SceneObject * compileCObjectsDataSource(const uint8_t * source, size_t sourceSize)
{
    void * dynlib = compileDLLSource(source, sourceSize);

    SceneObject * result = malloc( sizeof(SceneObject) );

    SceneObject (*buildObject)() = extractSymbolFromDLL(dynlib, "buildObject");
    *result = buildObject();

    result->shader = extractSymbolFromDLL(dynlib, "shader");
    result->get_distance = extractSymbolFromDLL(dynlib, "get_distance");
    result->getNormal = extractSymbolFromDLL(dynlib, "getNormal");

    return result;
};

void * extractDataFromRawData(void * data, uint64_t dataLength, uint8_t * extracteDataType, size_t * extractedDataLen)
{
    void * result;

    printf("Data version:    %hu\n", ((DataHeader*)data)->version);
    printf("Data length:     %llu\n", ((DataHeader*)data)->dataLength);
    printf("Data data type:  %hhu\n", ((DataHeader*)data)->dataType);

    *extracteDataType = ((DataHeader*)data)->dataType;

    if(((DataHeader*)data)->dataType == RAYMARCHER_DATA_ENTITY_HEADER_DATA_TYPE_OBJECT_DATA)
    {
        void * result = compileCObjectsDataSource
        (
            ((uint8_t *) data + sizeof( DataHeader ) + sizeof(ObjectDataHeader)),
            ((ObjectDataHeader*) ( data + sizeof( DataHeader )) )->sourceSize
        );

        return result;
    }

    return NULL;
};

void * packDataIntoRaw(void * data, size_t dataLen, uint8_t dataType, size_t * rawSize)
{
    void * result = malloc( sizeof(DataHeader) + dataLen );

    DataHeader header =
    {
        .version = RAYMARCHER_DATA_ENTITY_PROCESSOR_VERSION,
        .dataLength = dataLen,
        .dataType = dataType
    };

    memcpy(result, &header, sizeof(DataHeader));
    memcpy(result + sizeof(DataHeader), data, header.dataLength);

    *rawSize = sizeof(DataHeader) + dataLen;

    return result;
};

void * packObjectDataIntoRAW(SceneObject obj,
                                uint8_t * source,
                                size_t srcSize,
                                
                            size_t * rawSize)
{
    size_t resultSize = sizeof ( SceneObject ) + srcSize;
    void * result = malloc(resultSize);

    ObjectDataHeader header =
    {
        .sourceSize = srcSize
    };

    memcpy( result, &header, sizeof(header));
    memcpy( result + sizeof(header), source, srcSize);

    *rawSize = resultSize;

    return result;
};
#include "SceneEnviroment/Camera.h"
#include "SceneEnviroment/SceneEnviroment.h"
#include "SceneEnviroment/SceneObjects.h"
#include "Vec/Vec.h"
#include "MultithreadComputing/MultithreadComputing.h"
#include <stdio.h>
#include <math.h>
#include "DLLProcessor/DLLProcessor.h"
#include "SIngleLinkedList/SLL.h"



int main()
{   
    SceneObject obj =
    {
        {1,2,3},
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    };

    uint8_t objectFunctionsSource[] = \
    "#include <stdio.h> \n"

    "RGB shader(CameraRay * ray, SceneObject * this)"
    "{"
        "printf(\"\\nHello from shader function\\n\");"
        "return RGB_RED;"
    "}"

    "double get_distance(Vec3 point, SceneObject * this)"
    "{"
        "printf(\"\\nHello from distance function\\n\");"
        "return 3.14;"
    "}"

    "Vec3 getNormal(Vec3 point, SceneObject * this)"
    "{"
        "Vec3 res = {1,2,3};"
        "printf(\"\\nHello from normal function\\n\");"
        "return res;"
    "}"
    
    "SceneObject buildObject(){"
        "SceneObject result;"
        "result.objectSpecialData = malloc(sizeof(double));"
        "*((double * )result.objectSpecialData ) = 3.14;"

        "return result;"
    "}";


    printf("DLL test");

    size_t rawSize;

    void * objectRAW = packObjectDataIntoRAW(obj,

                                             &(objectFunctionsSource[0]),
                                             sizeof(objectFunctionsSource),   
                                            &rawSize);


    void * dataRaw = packDataIntoRaw(objectRAW, rawSize, RAYMARCHER_DATA_ENTITY_HEADER_DATA_TYPE_OBJECT_DATA, &rawSize);

    uint8_t extractedDataType;

    SceneObject * objectExtractedFromRAW = extractDataFromRawData(dataRaw, rawSize, &extractedDataType, &rawSize);

    Vec3 point;

    if( objectExtractedFromRAW->shader != NULL)
    {
        RGB res = objectExtractedFromRAW->shader(NULL, NULL);
        printf("%f %f %f\n", res.r,  res.g,  res.b);
    }

    if( objectExtractedFromRAW->get_distance != NULL)
    {
        printf("%f\n", objectExtractedFromRAW->get_distance(point, NULL));
    }

    if( objectExtractedFromRAW->getNormal != NULL)
    {
       Vec3 res = objectExtractedFromRAW->getNormal(point, NULL);

       printf("%f %f %f\n", res.x, res.y, res.z);
    }

    if(objectExtractedFromRAW->shader != NULL &&
       objectExtractedFromRAW->get_distance != NULL &&
       objectExtractedFromRAW->getNormal != NULL)
       {
           printf("DLL test passed!");
       }
       else
       {
           printf("ERROR PASSING DLL TEST!");
       }

       printf("Starting SLL test!");

    SLL list = getSLL();
    
    char * d0 = "ABOBA";
    char * d1 = "NIGGERS";
    char * d2 = "SNUS";
    char * d3 = "SUS";
    
    addNode(&list, d0);
    addNode(&list, d1);
    addNode(&list, d2);
    addNode(&list, d3);
    
    for (int i = 0; i < 4; ++i)
    {
        printf("%s\n", (char *)getNodeDataBySerialNumber(&list, i));
    }

    deleteNodeBySerialNumber(&list, 2);

    for (int i = 0; i < 3; ++i)
    {
        printf("%s\n", (char *)getNodeDataBySerialNumber(&list, i));
    }

    addNode(&list, d2);

    for (int i = 0; i < 4; ++i)
    {
        printf("%s\n", (char *)getNodeDataBySerialNumber(&list, i));
    }
    
    printf("Finished!\n");

    return -1;

    return 0;
};
#ifndef DATA_HEADER_H
#define DATA_HEADER_H

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../SceneEnviroment/Camera.h"
#include "../SceneEnviroment/SceneEnviroment.h"
#include "../SceneEnviroment/SceneObjects.h"
#include "../Vec/Vec.h"
#include "../MultithreadComputing/MultithreadComputing.h"
#include <dlfcn.h>

#ifndef RAYMARCHER_DATA_ENTITY_PROCESSOR_VERSION
    #define RAYMARCHER_DATA_ENTITY_PROCESSOR_VERSION 1
#endif

#define RAYMARCHER_DATA_ENTITY_HEADER_DATA_TYPE_OBJECT_DATA 1
#define RAYMARCHER_DATA_ENTITY_HEADER_DATA_TYPE_SCENE_ENVIROMENT_DATA 2
#define RAYMARCHER_DATA_ENTITY_HEADER_DATA_TYPE_COMMAND 3

typedef struct DataHeader
{
    uint16_t version;

    uint8_t dataType;
    uint64_t dataLength;
} DataHeader;

typedef struct ObjectDataHeader
{
    uint64_t sourceSize;
} ObjectDataHeader;

typedef struct SceneEnviromentDataHeader
{
    Camera main_camera;
    uint64_t objects_count;
} SceneEnviromentDataHeader;

typedef struct CommandHeader
{
    uint8_t command;
    uint64_t dataLength;
} CommandHeader;

void * compileDLLSource(const uint8_t * source, size_t sourceSize);

void * extractSymbolFromDLL(void * dynlib, char * symbolName);

SceneObject * compileCObjectsDataSource(const uint8_t * source, size_t sourceSize);

void * extractDataFromRawData(void * data, uint64_t dataLength,
                              uint8_t * extracteDataType, size_t * extractedDataLen);;

void * packDataIntoRaw(void * data, size_t dataLen, uint8_t dataType, size_t * rawSize);

void * packObjectDataIntoRAW(SceneObject obj,
                             
                             uint8_t * source,
                             size_t srcSize,
                             
                             size_t * rawSize);

#endif
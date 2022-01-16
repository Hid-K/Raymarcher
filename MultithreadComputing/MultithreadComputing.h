#ifndef RAYMARCHER_MULTITHREAD_COMPUTING
#define RAYMARCHER_MULTITHREAD_COMPUTING

#include "../RGB/RGB.h"
#include "../Vec/Vec.h"
#include "../SceneEnviroment/SceneEnviroment.h"
#include <pthread.h>
#include "unistd.h"

typedef struct RenderThreadArgs
{
    Vec2 n;
    Vec2 n1;

    int * status;
} RenderThreadArgs;

static RGB * frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING;
static SceneEnviroment * scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING;

static size_t windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING;
static size_t windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING;

static size_t threadsCount;

static pthread_t * threads = NULL;

static int * threadStatus = NULL;

static RenderThreadArgs * threadArgs = NULL;

void * renderThread(void * a);

void initMultithreadComputer(RGB * frame_buffer,
                             SceneEnviroment * scieneEnv,
                             size_t windowWidth,
                             size_t windowHeight,
                             size_t tc);

int checkThreadsStatus();

void startRender();

#endif
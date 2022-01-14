#ifndef RAYMARCHER_MULTITHREAD_COMPUTING
#define RAYMARCHER_MULTITHREAD_COMPUTING

#include "../../RGB/RGB.h"
#include "../../Vec/Vec.h"
#include "../../SceneEnviroment/SceneEnviroment.h"
#include <pthread.h>
#include "unistd.h"


static RGB * frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING;
static SceneEnviroment * scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING;

static size_t windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING;
static size_t windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING;

void * render0_127to0_127pixels(void * a)
{
    Vec2 n = {0,0};
    Vec2 n1 = {127, 127};

    render_frame_of_enviroment_PARALEL(frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING, n, n1, windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING, windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING, scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING);

    *( ( int * ) a ) = 10;
    pthread_exit(NULL);
};

void * render127_256to0_127pixels(void * a)
{
    Vec2 n = {127,0};
    Vec2 n1 = {255, 127};

    render_frame_of_enviroment_PARALEL(frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING, n, n1, windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING, windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING, scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING);

    *( ( int * ) a ) = 10;
    pthread_exit(NULL);
};

void * render0_127to127_256pixels(void * a)
{
    Vec2 n = {0,127};
    Vec2 n1 = {127, 255};

    render_frame_of_enviroment_PARALEL(frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING, n, n1, windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING, windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING, scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING);

    *( ( int * ) a ) = 10;
    pthread_exit(NULL);
};

void * render127_256to127_256pixels(void * a)
{
    Vec2 n = {127,127};
    Vec2 n1 = {255, 255};

    render_frame_of_enviroment_PARALEL(frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING, n, n1, windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING, windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING, scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING);

    *( ( int * ) a ) = 10;
    pthread_exit(NULL);
};

void initMultithreadComputer(RGB * frame_buffer, SceneEnviroment * scieneEnv, size_t windowWidth, size_t windowHeight)
{
    frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING = frame_buffer;
    scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING = scieneEnv;

    windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING = windowWidth;
    windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING = windowHeight;
};

void startRender()
{
    pthread_t threads[4];

    int threadStatus[4] =
    {
        0,0,0,0
    };
    
    pthread_create(&threads[0], NULL, render0_127to0_127pixels, &threadStatus[0]);
    pthread_join(threads[0], NULL);

    pthread_create(&threads[1], NULL, render127_256to0_127pixels, &threadStatus[1]);
    pthread_join(threads[1], NULL);
    
    pthread_create(&threads[2], NULL, render0_127to127_256pixels, &threadStatus[2]);
    pthread_join(threads[2], NULL);

    pthread_create(&threads[3], NULL, render127_256to127_256pixels, &threadStatus[3]);
    pthread_join(threads[3], NULL);

    for(int i = 0; i < 4; ++i)
    if(!threads[i])
    {
        printf("Error:unable to create thread, %d\n", i);
    }
    
    for(;
        threadStatus[0] != 10 &&
        threadStatus[1] != 10 &&
        threadStatus[2] != 10 &&
        threadStatus[3] != 10
    ;usleep( 1 ) )
    {
        // printf("Thread 0 status: %i\nThread 1 status: %i\nThread 2 status: %i\nThread 3 status: %i\n",
        // threadStatus[0],
        // threadStatus[1],
        // threadStatus[2],
        // threadStatus[3]);
    }
};

#endif
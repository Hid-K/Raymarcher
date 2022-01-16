#include "MultithreadComputing.h"

extern RGB * frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING;
extern SceneEnviroment * scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING;

extern size_t windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING;
extern size_t windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING;

extern size_t threadsCount;

extern pthread_t * threads;

extern int * threadStatus;

void * renderThread(void * a)
{
    Vec2 n =  ((RenderThreadArgs *)a)->n;
    Vec2 n1 = ((RenderThreadArgs *)a)->n1;

    render_frame_of_enviroment_PARALEL(frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING, n, n1, windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING, windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING, scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING);

    *( ( RenderThreadArgs * ) a )->status = 10;
    pthread_exit(NULL);
};

void initMultithreadComputer(RGB * frame_buffer,
                             SceneEnviroment * scieneEnv,
                             size_t windowWidth,
                             size_t windowHeight,
                             size_t tc)
{
    frame_buffer_RAYMARCHER_MULTITHREAD_COMPUTING = frame_buffer;
    scieneEnv_RAYMARCHER_MULTITHREAD_COMPUTING = scieneEnv;

    windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING = windowWidth;
    windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING = windowHeight;

    threadsCount = tc;

    threads = (pthread_t *)malloc( sizeof( pthread_t ) * threadsCount );

    threadStatus = (int *)malloc( sizeof( int ) * threadsCount );

    threadArgs = (RenderThreadArgs *)malloc( sizeof( RenderThreadArgs ) * threadsCount );

    double tps = sqrt( threadsCount ); //Threads per side

    Vec2 threadFrame = {windowWidth_RAYMARCHER_MULTITHREAD_COMPUTING/tps,
                        windowHeight_RAYMARCHER_MULTITHREAD_COMPUTING/tps};

    for (size_t i = 0; i < threadsCount; ++i)
    {
        threadArgs[i].n.x = ( i % (int)tps ) * threadFrame.x;
        threadArgs[i].n.y = ( i / (int)tps ) * threadFrame.y;

        threadArgs[i].n1 = add(threadArgs[i].n, threadFrame);

        threadArgs[i].status = &threadStatus[i];
    }
};

int checkThreadsStatus()
{
    for (size_t i = 0; i < threadsCount; ++i)
    {
        if(threadStatus[i] == 0) return 0;
    }

    return 10;
};

void startRender()
{
    for (size_t i = 0; i < threadsCount; ++i)
    {
        threadStatus[i] = 0;
        pthread_create(&threads[i], NULL, renderThread, &threadArgs[i]);
        pthread_join(threads[i], NULL);
    }

    for(int i = 0; i < threadsCount; ++i)
    if(!threads[i])
    {
        printf("ERROR: unable to create thread, %i\n", i);
    }
    
    for( ; checkThreadsStatus() <= 0 ; usleep( 1 ) );
};
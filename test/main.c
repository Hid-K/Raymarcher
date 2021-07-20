#include "../Vec/Vec.h"
#include "../SceneEnviroment/SceneEnviroment.h"
#include <SDL.h>
#include <stddef.h>
#include "../SceneEnviroment/SceneObjects.h"

size_t windowWidth = 255;
size_t windowHeight = 255;

int main()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Cant init SDL\n");
        return -1;
    };


    SDL_Window * mainWindow = SDL_CreateWindow("HidRaymarcher 2.0", 0, 0, windowWidth, windowHeight,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

    if(mainWindow == NULL)
    {
        printf("Cant create main window\n");
        return -1;
    };


    SDL_Renderer * mainWindowRenderer = SDL_CreateRenderer(mainWindow, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(mainWindowRenderer == NULL)
    {
        printf("Cant create main window renderer\n");
        return -1;
    };

    SDL_Event event;
    char quit = 0;

    RGB * frame_buffer = malloc(sizeof(RGB) * windowHeight * windowWidth);

    if(frame_buffer == NULL)
    {
        printf ("ERROR: Cannot get memory for frame buffer!\n");
    };

    SceneEnviroment scieneEnv =
    {
        {
            {0,0,50},
            {1,0,0},
            {0,1,0},
            {0,0,1},
            200
        },
        0,
        1,
        malloc(sizeof(struct SceneObject) * scieneEnv.objects_count)
    };

    Vec3 SCobjectPos = {0,0,0};

    SceneObject SCobject = createSimpleSphere(5, SCobjectPos, &scieneEnv);

    memcpy(&scieneEnv.objects[0], &SCobject, sizeof(SCobject));

    // SCobjectPos.x = 10;
    // SCobjectPos.y = 10;
    // SCobjectPos.z = 10;

    // SCobject = createSimpleSphere(5, SCobjectPos, &scieneEnv);

    // memcpy(&scieneEnv.objects[1], &SCobject, sizeof(SCobject));

    // SCobject = createSimpleFlatSurface(&scieneEnv, 0);

    // memcpy(&scieneEnv.objects[1], &SCobject, sizeof(SCobject));

    Vec2 n = {0,0};
    Vec2 n1 = {windowWidth,windowHeight};

    double camXDAngle = M_PI/6;
    double camYDAngle = M_PI/50;
    double camZDAngle = 0;

    for(;quit == 0;)
    {
        scieneEnv.main_camera.direction = rotateAboutX(scieneEnv.main_camera.direction, camXDAngle);
        scieneEnv.main_camera.right     = rotateAboutX(scieneEnv.main_camera.right,     camXDAngle);
        scieneEnv.main_camera.up        = rotateAboutX(scieneEnv.main_camera.up,        camXDAngle);
        // scieneEnv.main_camera.direction = rotateAboutY(scieneEnv.main_camera.direction, camYDAngle);
        // scieneEnv.main_camera.direction = rotateAboutZ(scieneEnv.main_camera.direction, camZDAngle);

        // camXDAngle = 0;
        // camYDAngle = 0;
        // camZDAngle = 0;

        // scieneEnv.main_camera.up = rotateAboutX(scieneEnv.main_camera.up, a);

        // scieneEnv.main_camera.origin.x +=10;

        // printf("Camera origin x = %f\n Camera origin y = %f\n Camera origin z = %f\n",
        //     scieneEnv.main_camera.origin.x,scieneEnv.main_camera.origin.y,scieneEnv.main_camera.origin.z);

        // printf("x = %f, y = %f, z = %f",
        // scieneEnv.main_camera.direction.x
        // , scieneEnv.main_camera.direction.y
        // , scieneEnv.main_camera.direction.z);

        for(;SDL_PollEvent(&event);)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = 1;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    Vec2 startPos = {(double)event.button.x, (double)event.button.y};
                    Vec2 stopPos;
                    for(;SDL_PollEvent(&event);)
                    {
                        stopPos.x = (double)event.button.x;
                        stopPos.y = (double)event.button.y;
                    };
                    Vec2 dPos = substract(stopPos, startPos);
                    
                    // camZDAngle = dPos.x/100;
                    // camYDAngle = dPos.y/100;
                };
            break;

            case SDL_WINDOWEVENT:

                if(event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    windowWidth = event.window.data1;
                    windowHeight = event.window.data2;

                    free(frame_buffer);

                    frame_buffer = malloc(sizeof(RGB) * windowHeight * windowWidth);
                    if(frame_buffer != NULL)
                    {
                        n1.x = windowWidth;
                        n1.y = windowHeight;
                        printf ("MESSAGE: Window size succesfully changed!\n");
                    } else
                    {
                        printf ("ERROR: Cannot get memory for frame buffer!\n");
                    };
                };

            break;
            
            default:
                break;
            }
        };
        

        render_frame_of_enviroment_PARALEL(frame_buffer, n, n1, windowHeight, windowWidth, &scieneEnv);
        // render_frame_of_enviroment_PERSPECTIVE(&frame_buffer[0][0], n, n1, 255, 255, &scieneEnv);
        SDL_RenderClear(mainWindowRenderer);
        for(size_t x = 0; x < windowWidth; ++x)
        {
            for(size_t y = 0; y < windowHeight; ++y)
            {
                SDL_SetRenderDrawColor(mainWindowRenderer,
                                       255*frame_buffer[x + y * windowWidth].r,
                                       255*frame_buffer[x + y * windowWidth].g,
                                       255*frame_buffer[x + y * windowWidth].b,
                                       255);
                SDL_RenderDrawPoint(mainWindowRenderer, y, x);
            };
        };
        SDL_RenderPresent(mainWindowRenderer);

        SDL_Delay(1000/6);
        printf("Rendered!\n");
    };

    return 0;
};
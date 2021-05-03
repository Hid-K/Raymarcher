#include "Vec3.h"
#include "Vec2.h"
#include "SceneEnviroment.h"
#include <SDL.h>
#include <stddef.h>
#include "SceneObjects.h"

size_t windowWidth = 255;
size_t windowHeight = 255;

double camXYAngle = 0;
double camZYAngle = 0;

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

    RGB frame_buffer[255][255];

    SceneEnviroment scieneEnv =
    {
        {
            {0,0,0},
            {0,1,0},
            {0,0,1},
            {1,0,0},
            100
        },
        0,
        malloc(sizeof(struct SceneObject) * 2)
    };

    Vec3 SCobjectPos = {0,10,0};

    SceneObject SCobject = createSimpleSphere(5, SCobjectPos);

    memcpy(&scieneEnv.objects[0], &SCobject, sizeof(SCobject));

    SCobjectPos.x = 20;
    SCobjectPos.y = 11;
    SCobjectPos.z = 20;

    SCobject = createSimpleSphere(5, SCobjectPos);

    memcpy(&scieneEnv.objects[1], &SCobject, sizeof(SCobject));

    Vec2 n = {0,0};
    Vec2 n1 = {255,255};

    for(;quit == 0;)
    {
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
                    // struct Vec2 startPos = {(double)event.button.x, (double)event.button.y};
                    // struct Vec2 stopPos;
                    // for(;SDL_PollEvent(&event);)
                    // {
                    //     stopPos = {(double)event.button.x, (double)event.button.y};
                    // };
                    // struct Vec2 dPos = stopPos - startPos;
                    // camXYAngle = (dPos.x/M_PI)/50;
                    // camZYAngle = (dPos.y/M_PI)/50;
                };
            break;

            case SDL_WINDOWEVENT:

                if(event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    windowWidth = event.window.data1;
                    windowHeight = event.window.data2;
                };

            break;
            
            default:
                break;
            }
        };
        
        SDL_RenderClear(mainWindowRenderer);
        render_frame_of_enviroment(&frame_buffer[0][0], 255, 255, &scieneEnv);
        for(size_t x = 0; x < windowWidth; ++x)
        {
            for(size_t y = 0; y < windowHeight; ++y)
            {
                SDL_SetRenderDrawColor(mainWindowRenderer, 255*frame_buffer[x][y].r, 255*frame_buffer[x][y].g, 255*frame_buffer[x][y].b, 255);
                SDL_RenderDrawPoint(mainWindowRenderer, x, y);
            };
        };
        SDL_RenderPresent(mainWindowRenderer);

        SDL_Delay(1000/6);
        printf("Rendered!\n");
    };

    return 0;
};
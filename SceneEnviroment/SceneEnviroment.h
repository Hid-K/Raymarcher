#ifndef SCENEENVIROMENT_H
#define SCENEENVIROMENT_H

#include "Camera.h"
#include "../Vec/Vec.h"
#include <stddef.h>
#include <stdlib.h>
#include "../RGB.h"

typedef struct SceneObject SceneObject;

typedef struct SceneEnviroment
{
    Camera main_camera;

    double ticks_count;

    SceneObject * objects;
} SceneEnviroment;

void render_frame_of_enviroment_PARALEL(RGB * frameBuffer,
                                size_t buffer_height,
                                size_t buffer_width,
                                SceneEnviroment * enviroment);

void render_frame_of_enviroment_PERSPECTIVE(RGB * frameBuffer,
                                size_t buffer_height,
                                size_t buffer_width,
                                SceneEnviroment * enviroment);

RGB castRay(Vec3 origin, Vec3 direction, SceneEnviroment * enviroment);

SceneObject * getNearestObject(SceneEnviroment * scene, Vec3 point, double * dest);

#endif
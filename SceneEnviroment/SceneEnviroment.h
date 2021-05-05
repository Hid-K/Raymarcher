#ifndef SCENEENVIROMENT_H
#define SCENEENVIROMENT_H

#include "Camera.h"
#include "../Vec/Vec.h"
#include <stddef.h>
#include <stdlib.h>
#include "../RGB.h"
#include <stdio.h>

static const double NEAR = 0.001;

typedef struct SceneObject SceneObject;

typedef struct SceneEnviroment
{
    Camera main_camera;

    double ticks_count;

    size_t objects_count;

    SceneObject * objects;
} SceneEnviroment;

void render_frame_of_enviroment_PARALEL(RGB * frameBuffer,
                                        Vec2 left_up_render_corner,
                                        Vec2 right_down_render_corner,
                                        size_t buffer_height,
                                        size_t buffer_width,
                                        SceneEnviroment * enviroment);
/*
void render_frame_of_enviroment_PERSPECTIVE(RGB * frameBuffer,
                                size_t buffer_height,
                                size_t buffer_width,
                                SceneEnviroment * enviroment);
*/
RGB castRay(CameraRay * ray, SceneEnviroment * enviroment);

SceneObject * getNearestObject(SceneEnviroment * scene, Vec3 point, double * dest);

#endif
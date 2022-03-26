#ifndef SCENEENVIROMENT_H
#define SCENEENVIROMENT_H

#include "Camera.h"
#include "../Vec/Vec.h"
#include <stddef.h>
#include <stdlib.h>
#include "../RGB/RGB.h"
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

double sphereDestFunction(Vec3 point, SceneObject * this);

void render_frame_of_enviroment_PARALEL(RGB * frameBuffer,
                                        Vec2 left_up_render_corner,
                                        Vec2 right_down_render_corner,
                                        size_t buffer_height,
                                        size_t buffer_width,
                                        SceneEnviroment * enviroment);

void render_frame_of_enviroment_PERSPECTIVE(RGB * frameBuffer,
                                        Vec2 left_up_render_corner,
                                        Vec2 right_down_render_corner,
                                        size_t buffer_height,
                                        size_t buffer_width,
                                        SceneEnviroment * enviroment);

RGB castRay(CameraRay * ray, SceneEnviroment * enviroment);

int sign(double a);

SceneObject * getNearestObject(SceneEnviroment * scene, Vec3 point, double * dest);

double sdSmoothUnion( double d1, double d2, double k ) 
{
    float h = clamp( 0.5 + 0.5*(d2-d1)/k, 0.0, 1.0 );
    return mix( d2, d1, h ) - k*h*(1.0-h); 
}

#endif
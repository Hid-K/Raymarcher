#ifndef CAMERA_H
#define CAMERA_H

#include "Vec2.h"
#include "Vec3.h"


typedef struct
{
    Vec3 origin;
    Vec3 direction;
    Vec3 up;
    Vec3 right;

    double FOV;
} Camera;

typedef struct
{
    Vec3 origin;
    Vec3 end;
    Vec3 direction;

    Camera * parentCamera;
} CameraRay;

#endif
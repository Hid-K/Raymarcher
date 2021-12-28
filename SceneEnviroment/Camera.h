#ifndef CAMERA_H
#define CAMERA_H

#include "../Vec/Vec.h"
#include <stddef.h>
#include "../RGB/RGB.h"

typedef struct
{
    Vec3 origin;
    Vec3 right;
    Vec3 direction;
    Vec3 up;

    double FOV;
} Camera;

typedef struct
{
    Vec3 origin;
    Vec3 end;
    Vec3 direction;

    double path_way;

    size_t reflections_count;

    size_t steps_count;

    RGB color;

    Camera * parentCamera;
} CameraRay;

#endif
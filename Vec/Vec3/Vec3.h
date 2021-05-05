#ifndef VEC3_H
#define VEC3_H

#include <math.h>

typedef struct
{
    double x,y,z;
} Vec3;

Vec3 multiply(Vec3 a, double b);

Vec3 add(Vec3 a, Vec3 b);

double length(Vec3 a);

Vec3 normalize(Vec3 a);

Vec3 substract(Vec3 a, Vec3 b);

Vec3 divide(Vec3 a, double b);

double prod(Vec3 a, Vec3 b);

Vec3 getReflection(Vec3 n, Vec3 l);

#endif
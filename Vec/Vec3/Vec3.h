#ifndef VEC3_H
#define VEC3_H

#include <math.h>

typedef struct
{
    double x,y,z;
} Vec3;

Vec3 __attribute__((overloadable)) multiply(Vec3 a, double b);

Vec3 __attribute__((overloadable)) add(Vec3 a, Vec3 b);

double __attribute__((overloadable)) length(Vec3 a);

Vec3 __attribute__((overloadable)) normalize(Vec3 a);

Vec3 __attribute__((overloadable)) rotateAboutX(Vec3 v, double a);

Vec3 __attribute__((overloadable)) rotateAboutY(Vec3 v, double a);

Vec3 __attribute__((overloadable)) rotateAboutZ(Vec3 v, double a);

Vec3 __attribute__((overloadable)) substract(Vec3 a, Vec3 b);

Vec3 __attribute__((overloadable)) divide(Vec3 a, double b);

double __attribute__((overloadable)) prod(Vec3 a, Vec3 b);

Vec3 __attribute__((overloadable)) getReflection(Vec3 n, Vec3 l);

Vec3 __attribute__((overloadable)) absv(Vec3 a);

#endif
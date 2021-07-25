#ifndef VEC2_H
#define VEC2_H

#include <math.h>

typedef struct
{
    double x,y;
} Vec2;

Vec2 multiply(Vec2 a, double b);

Vec2 add(Vec2 a, Vec2 b);

double length(Vec2 a);

Vec2 normalize(Vec2 a);

// Vec2 rotateAboutX(Vec2 v, double a);

// Vec2 rotateAboutY(Vec2 v, double a);

// Vec2 rotateAboutZ(Vec2 v, double a);

Vec2 substract(Vec2 a, Vec2 b);

Vec2 divide(Vec2 a, double b);

double prod(Vec2 a, Vec2 b);

Vec2 getReflection(Vec2 n, Vec2 l);

Vec2 absv(Vec2 a);

#endif
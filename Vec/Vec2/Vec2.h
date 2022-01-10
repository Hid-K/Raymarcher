#ifndef VEC2_H
#define VEC2_H

#include <math.h>

typedef struct Vec2
{
    double x,y;
} Vec2;

Vec2 multiply_Vec2(Vec2 a, double b);

Vec2 add_Vec2(Vec2 a, Vec2 b);

double length_Vec2(Vec2 a);

Vec2 normalize_Vec2(Vec2 a);

// Vec2 rotateAboutX_Vec2(Vec2 v, double a);

// Vec2 rotateAboutY_Vec2(Vec2 v, double a);

// Vec2 rotateAboutZ_Vec2(Vec2 v, double a);

Vec2 substract_Vec2(Vec2 a, Vec2 b);

Vec2 divide_Vec2(Vec2 a, double b);

double prod_Vec2(Vec2 a, Vec2 b);

Vec2 getReflection_Vec2(Vec2 n, Vec2 l);

Vec2 absv_Vec2(Vec2 a);

#endif
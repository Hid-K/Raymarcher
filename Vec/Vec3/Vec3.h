#ifndef VEC3_H
#define VEC3_H

#include <math.h>

typedef struct Vec3
{
    double x,y,z;
} Vec3;

Vec3  multiply_Vec3(Vec3 a, double b);

Vec3  add_Vec3(Vec3 a, Vec3 b);

double  length_Vec3(Vec3 a);

Vec3  normalize_Vec3(Vec3 a);

Vec3  rotateAboutX_Vec3(Vec3 v, double a);

Vec3  rotateAboutY_Vec3(Vec3 v, double a);

Vec3  rotateAboutZ_Vec3(Vec3 v, double a);

Vec3  substract_Vec3(Vec3 a, Vec3 b);

Vec3  divide_Vec3(Vec3 a, double b);

double  prod_Vec3(Vec3 a, Vec3 b);

Vec3  getReflection_Vec3(Vec3 n, Vec3 l);

Vec3  absv_Vec3(Vec3 a);

Vec3  vabs_Vec3(Vec3 a);

Vec3  vfloor_Vec3(Vec3 a);

#endif
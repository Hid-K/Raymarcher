#ifndef RGB_STRUCT_H
#define RGB_STRUCT_H

#include "../Vec/Vec.h"

typedef struct
{
    double r,g,b;
} RGB;

void normalize_color(RGB * color);

RGB add_color_RGB(RGB a, RGB b);
RGB add_color_VEC3(RGB a, Vec3 b);
RGB add_color_DOUBLE(RGB a, double b);

#define  add_color(a, b)\
    _Generic(      \
    (b),            \
    RGB : add_color_RGB, \
    Vec3 : add_color_VEC3, \
    double : add_color_DOUBLE   \
    ) ((a), (b))

static const RGB RGB_RED  = {1,0,0};
static const RGB RGB_GREN = {0,1,0};
static const RGB RGB_BLU  = {0,0,1};
static const RGB RGB_WHI  = {1,1,1};
static const RGB RGB_BLACK = {0,0,0};

#endif
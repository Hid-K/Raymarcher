#include "RGB.h"

inline void normalize_color(RGB * color)
{
    if(color->r < 0) color->r = 0;
    if(color->g < 0) color->g = 0;
    if(color->b < 0) color->b = 0;

    if(color->r > 1) color->r = 1;
    if(color->g > 1) color->g = 1;
    if(color->b > 1) color->b = 1;
};

inline __attribute__((overloadable)) RGB add_color(RGB a, RGB b)
{
    RGB res;

    res.r = a.r + b.r;
    res.g = a.g + b.g;
    res.b = a.b + b.b;

    return res;

};

inline RGB __attribute__((overloadable)) add_color(RGB a, Vec3 b)
{
    RGB res;

    res.r = a.r + b.x;
    res.g = a.g + b.y;
    res.b = a.b + b.z;

    return res;
};

inline RGB __attribute__((overloadable)) add_color(RGB a, double b)
{
    RGB res;

    res.r = a.r + b;
    res.g = a.g + b;
    res.b = a.b + b;

    return res;
};

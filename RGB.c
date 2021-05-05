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

inline RGB add_color(RGB a, RGB b)
{
    RGB res;

    res.r = a.r + b.r;
    res.g = a.g + b.g;
    res.b = a.b + b.b;

    return res;

};
#include "../Vec.h"

inline Vec2 multiply_Vec2(Vec2 a, double b)
{
    Vec2 result = {a.x*b, a.y*b};
    return result;
};

inline Vec2 add_Vec2(Vec2 a, Vec2 b)
{
    Vec2 result = {a.x+b.x, a.y+b.y};
    return result;
};

inline Vec2 normalize_Vec2(Vec2 a)
{
    double l = length(a);
    Vec2 result = {a.x/l, a.y/l};
    return result;
};

inline double length_Vec2(Vec2 a)
{
    return sqrt(a.x*a.x + a.y*a.y);
};

inline Vec2 substract_Vec2(Vec2 a, Vec2 b)
{
    Vec2 result = {a.x-b.x, a.y-b.y};
    return result;
};

inline Vec2 absv_Vec2(Vec2 a)
{
    a.x = fabs(a.x);
    a.y = fabs(a.y);
    return a;
};

inline Vec2 divide_Vec2(Vec2 a, double b)
{
    Vec2 result = {a.x/b, a.y/b,};
    return result;
};

double prod_Vec2(Vec2 a, Vec2 b)
{
    return a.x*b.x + a.y*b.y;
};

inline Vec2 getReflection_Vec2(Vec2 n, Vec2 l)
{
    return substract(multiply(n,prod(n,l)*2), l);
};
#include "Vec3.h"

inline Vec3 multiply(Vec3 a, double b)
{
    Vec3 result = {a.x*b, a.y*b, a.z*b};
    return result;
};

inline Vec3 add(Vec3 a, Vec3 b)
{
    Vec3 result = {a.x+b.x, a.y+b.y, a.z+b.z};
    return result;
};

inline Vec3 normalize(Vec3 a)
{
    double l = length(a);
    Vec3 result = {a.x/l, a.y/l, a.z/l};
    return result;
};

inline double length(Vec3 a)
{
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
};

inline Vec3 substract(Vec3 a, Vec3 b)
{
    Vec3 result = {a.x-b.x, a.y-b.y, a.z-b.z};
    return result;
};

inline Vec3 divide(Vec3 a, double b)
{
    Vec3 result = {a.x/b, a.y/b, a.z/b};
    return result;
};

double prod(Vec3 a, Vec3 b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
};

inline Vec3 getReflection(Vec3 n, Vec3 l)
{
    return substract(multiply(n,prod(n,l)*2), l);
};
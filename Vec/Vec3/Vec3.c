#include "Vec3.h"

inline Vec3 __attribute__((overloadable)) multiply(Vec3 a, double b)
{
    Vec3 result = {a.x*b, a.y*b, a.z*b};
    return result;
};

inline Vec3 __attribute__((overloadable)) add(Vec3 a, Vec3 b)
{
    Vec3 result = {a.x+b.x, a.y+b.y, a.z+b.z};
    return result;
};

inline Vec3 __attribute__((overloadable)) normalize(Vec3 a)
{
    double l = length(a);
    Vec3 result = {a.x/l, a.y/l, a.z/l};
    return result;
};

Vec3 __attribute__((overloadable)) rotateAboutX(Vec3 v, double a)
{
    Vec3 c1 = {1,0     ,0      };
    Vec3 c2 = {0,cos(a),-sin(a)};
    Vec3 c3 = {0,sin(a),cos(a) };

    Vec3 res = {prod(v, c1), prod(v, c2), prod(v, c3)};

    return res;
};

Vec3 __attribute__((overloadable)) rotateAboutY(Vec3 v, double a)
{
    Vec3 c1 = {cos(a),0,sin(a)};
    Vec3 c2 = {0,1,0};
    Vec3 c3 = {-sin(a),0,cos(a)};

    Vec3 res = {prod(v, c1), prod(v, c2), prod(v, c3)};

    return res;
};

Vec3 __attribute__((overloadable)) rotateAboutZ(Vec3 v, double a)
{
    Vec3 c1 = {cos(a),-sin(a),0};
    Vec3 c2 = {sin(a),cos(a),0};
    Vec3 c3 = {0,0,1};

    Vec3 res = {prod(v, c1), prod(v, c2), prod(v, c3)};

    return res;
};

inline double __attribute__((overloadable)) length(Vec3 a)
{
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
};

inline Vec3 __attribute__((overloadable)) substract(Vec3 a, Vec3 b)
{
    Vec3 result = {a.x-b.x, a.y-b.y, a.z-b.z};
    return result;
};

static inline double __attribute__((overloadable)) absd(double a)
{
    if(a < 0)   return -a;
    if(a > 0)   return a;
    return 0;
};

inline Vec3 __attribute__((overloadable)) absv(Vec3 a)
{
    a.x = absd(a.x);
    a.y = absd(a.y);
    a.z = absd(a.z);
    return a;
};

inline Vec3 __attribute__((overloadable)) divide(Vec3 a, double b)
{
    Vec3 result = {a.x/b, a.y/b, a.z/b};
    return result;
};

double __attribute__((overloadable)) prod(Vec3 a, Vec3 b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
};

inline Vec3 __attribute__((overloadable)) getReflection(Vec3 n, Vec3 l)
{
    return substract(l, multiply(n, 2 * prod(n, l)));
};
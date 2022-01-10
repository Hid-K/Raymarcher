#include "../Vec.h"

inline Vec3 multiply_Vec3(Vec3 a, double b)
{
    Vec3 result = {a.x*b, a.y*b, a.z*b};
    return result;
};

inline Vec3 add_Vec3(Vec3 a, Vec3 b)
{
    Vec3 result = {a.x+b.x, a.y+b.y, a.z+b.z};
    return result;
};

inline Vec3 normalize_Vec3(Vec3 a)
{
    double l = length(a);
    Vec3 result = {a.x/l, a.y/l, a.z/l};
    return result;
};

inline Vec3 rotateAboutX_Vec3(Vec3 v, double a)
{
    Vec3 c1 = {1,0     ,0      };
    Vec3 c2 = {0,cos(a),-sin(a)};
    Vec3 c3 = {0,sin(a),cos(a) };

    Vec3 res = {prod(v, c1), prod(v, c2), prod(v, c3)};

    return res;
};

inline Vec3 rotateAboutY_Vec3(Vec3 v, double a)
{
    Vec3 c1 = {cos(a),0,sin(a)};
    Vec3 c2 = {0,1,0};
    Vec3 c3 = {-sin(a),0,cos(a)};

    Vec3 res = {prod(v, c1), prod(v, c2), prod(v, c3)};

    return res;
};

inline Vec3 rotateAboutZ_Vec3(Vec3 v, double a)
{
    Vec3 c1 = {cos(a),-sin(a),0};
    Vec3 c2 = {sin(a),cos(a),0};
    Vec3 c3 = {0,0,1};

    Vec3 res = {prod(v, c1), prod(v, c2), prod(v, c3)};

    return res;
};

inline double length_Vec3(Vec3 a)
{
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
};

inline Vec3 substract_Vec3(Vec3 a, Vec3 b)
{
    Vec3 result = {a.x-b.x, a.y-b.y, a.z-b.z};
    return result;
};

static inline double absd_Vec3(double a)
{
    if(a < 0)   return -a;
    if(a > 0)   return a;
    return 0;
};

inline Vec3 absv_Vec3(Vec3 a)
{
    a.x = fabs(a.x);
    a.y = fabs(a.y);
    a.z = fabs(a.z);
    return a;
};

inline Vec3 divide_Vec3(Vec3 a, double b)
{
    Vec3 result = {a.x/b, a.y/b, a.z/b};
    return result;
};

inline double prod_Vec3(Vec3 a, Vec3 b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
};

inline Vec3 getReflection_Vec3(Vec3 n, Vec3 l)
{
    return substract(l, multiply(n, 2 * prod(n, l)));
};

inline Vec3 vabs_Vec3(Vec3 a)
{
    Vec3 r = {fabs(a.x), fabs(a.y), fabs(a.z)};
    return r;
};

inline Vec3 vfloor_Vec3(Vec3 a)
{
    Vec3 r = {floorf(a.x), floorf(a.y), floorf(a.z)};
    return r;
};
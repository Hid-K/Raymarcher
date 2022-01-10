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

// Vec2 rotateAboutX_Vec2(Vec2 v, double a)
// {
//     Vec2 c1 = {1,0     ,0      };
//     Vec2 c2 = {0,cos(a),-sin(a)};
//     Vec2 c3 = {0,sin(a),cos(a) };

//     Vec2 res = {prod(v, c1), prod(v, c2), prod(v, c3)};

//     return res;
// };

// Vec2 rotateAboutY_Vec2(Vec2 v, double a)
// {
//     Vec2 c1 = {cos(a),0,sin(a)};
//     Vec2 c2 = {0,1,0};
//     Vec2 c3 = {-sin(a),0,cos(a)};

//     Vec2 res = {prod(v, c1), prod(v, c2), prod(v, c3)};

//     return res;
// };

// Vec2 rotateAboutZ_Vec2(Vec2 v, double a)
// {
//     Vec2 c1 = {cos(a),-sin(a),0};
//     Vec2 c2 = {sin(a),cos(a),0};
//     Vec2 c3 = {0,0,0};

//     Vec2 res = {prod(v, c1), prod(v, c2), prod(v, c3)};

//     return res;
// };

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
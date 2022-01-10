#include "Vec3/Vec3.h"
#include "Vec2/Vec2.h"

#include <math.h>
#include <stdlib.h>

#define  multiply(a, b)\
    _Generic(           \
    (a),                 \
    Vec2 : multiply_Vec2, \
    Vec3 : multiply_Vec3   \
    ) ((a), (b))

#define  add(a, b)\
    _Generic(      \
    (a),            \
    Vec2 : add_Vec2, \
    Vec3 : add_Vec3   \
    ) ((a), (b))

#define  length(a)   \
    _Generic(         \
    (a),               \
    Vec2 : length_Vec2, \
    Vec3 : length_Vec3   \
    ) ((a))

#define  normalize(a)   \
    _Generic      (      \
    (a),                  \
    Vec2 : normalize_Vec2, \
    Vec3 : normalize_Vec3   \
    ) ((a))

#define  substract(a, b)\
    _Generic(            \
    (a),                  \
    Vec2 : substract_Vec2, \
    Vec3 : substract_Vec3   \
    ) ((a), (b))

#define  divide(a, b)\
    _Generic(         \
    (a),               \
    Vec2 : divide_Vec2, \
    Vec3 : divide_Vec3   \
    ) ((a), (b))

#define prod(a, b)\
    _Generic(      \
    (a),            \
    Vec2 : prod_Vec2, \
    Vec3 : prod_Vec3   \
    ) ((a), (b))

#define getReflection(a, b)\
    _Generic(               \
    (a),                      \
    Vec2 : getReflection_Vec2, \
    Vec3 : getReflection_Vec3   \
    ) ((a), (b))

#define rotateAboutX(v,a)\
    _Generic(             \
        (v),               \
        Vec3 : rotateAboutX_Vec3\
    ) ((v),(a))


#define rotateAboutY(v,a)\
    _Generic(             \
        (v),               \
        Vec3 : rotateAboutY_Vec3\
    ) ((v),(a))


#define rotateAboutZ(v,a)\
    _Generic(             \
        (v),               \
        Vec3 : rotateAboutZ_Vec3\
    ) ((v),(a))

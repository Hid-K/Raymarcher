#include "SceneObjects.h"

double sphereDestFunction(Vec3 point, const SceneObject * this)
{
    return length(substract(point, this->origin)) - *((double*)(this->objectSpecialData));
};

RGB simpleREDShader(const CameraRay * ray, const SceneObject * this)
{
    // double l =length(substract(ray->end, ray->origin));
    // RGB color = RGB_RED;
    // color.r /= l;
    return RGB_RED;
};

SceneObject createSimpleSphere(double radius, Vec3 origin)
{
    SceneObject sphere;

    sphere.get_distance = sphereDestFunction;
    sphere.shader = simpleREDShader;

    sphere.origin = origin;

    sphere.objectSpecialData = malloc(sizeof(double));

    *((double*)(sphere.objectSpecialData)) = radius;

    return sphere;
};
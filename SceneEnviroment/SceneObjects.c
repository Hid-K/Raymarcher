#include "SceneObjects.h"

double sphereDestFunction(Vec3 point, const SceneObject * this)
{
    return length(substract(point, this->origin)) - *((double*)(this->objectSpecialData));
};

RGB simpleREDShader(CameraRay * ray, const SceneObject * this)
{
    RGB color_spectrum = {0.1,-0.5,-0.5};
    if(ray->reflections_count <= 3)
    {
        Vec3 normal = normalize(substract(this->origin, ray->end));

        ray->direction = getReflection(ray->direction, normal);

        ray->origin = ray->end;
        ray->end = ray->origin;

        ray->reflections_count++;

        RGB res = castRay(ray, this->parentEnviroment);

        res = add_color(res, color_spectrum);

        return res;
    } else
    {
        return color_spectrum;
    };
};

SceneObject createSimpleSphere(double radius, Vec3 origin, SceneEnviroment * sceneEnv)
{
    SceneObject sphere;

    sphere.parentEnviroment = sceneEnv;

    sphere.get_distance = sphereDestFunction;
    sphere.shader = simpleREDShader;

    sphere.origin = origin;

    sphere.objectSpecialData = malloc(sizeof(double));

    *((double*)(sphere.objectSpecialData)) = radius;

    return sphere;
};
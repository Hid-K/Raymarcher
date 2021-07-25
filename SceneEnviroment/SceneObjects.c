#include "SceneObjects.h"

double sphereDestFunction(Vec3 point, const SceneObject * this)
{
    double res = length(substract(point, this->origin));
    double r = *((double*)(this->objectSpecialData));
    return res - r;
};

double surfaceDestFunction(Vec3 point, const SceneObject * this)
{
    return fabs(*((double*)(this->objectSpecialData)) - point.z);
};

RGB simpleRaindowShader(CameraRay * ray, const SceneObject * this)
{
    RGB color_spectrum = {0, 0, 0};
    if(ray->reflections_count <= 3)
    {
        Vec3 normal = normalize(substract(ray->end, this->origin));

        ray->direction = getReflection(normal, ray->direction);

        ray->origin = add(ray->end, multiply(normal, NEAR));
        ray->end = ray->origin;

        ray->reflections_count++;

        RGB res = castRay(ray, this->parentEnviroment);

        res = add_color(res, color_spectrum);

        res = add_color(res, *(RGB*)&normal);

        return res;
    } else
    {
        return color_spectrum;
    };
    return color_spectrum;
};


RGB simpleGRAYShader(CameraRay * ray, const SceneObject * this)
{
    RGB color_spectrum = {1, 1, 1};
    if(ray->reflections_count <= 3)
    {
        Vec3 normal = {0,0, (double)(fabs(*((double*)(this->objectSpecialData)) - ray->end.z)/(*((double*)(this->objectSpecialData)) - ray->end.z)) };

        if(isnan(normal.z)) normal.z = 0;

        // printf("\n%f\n", this->get_distance(add(ray->end, normal), this));
        // printf("%f\n",   this->get_distance(ray->end,              this));

        ray->direction = getReflection(normal, ray->direction);

        ray->origin = add(ray->end, multiply(normal, NEAR+NEAR/10));
        ray->end = ray->origin;

        ray->reflections_count++;

        RGB res = castRay(ray, this->parentEnviroment);

        res = add_color(res, color_spectrum);

        return res;
    } else
    {
        return color_spectrum;
    };
    return color_spectrum;
};



SceneObject createSimpleSphere(double radius, Vec3 origin, SceneEnviroment * sceneEnv)
{
    SceneObject sphere;

    sphere.parentEnviroment = sceneEnv;

    sphere.get_distance = sphereDestFunction;
    sphere.shader = simpleRaindowShader;

    sphere.origin = origin;

    sphere.objectSpecialData = malloc(sizeof(double));

    *((double*)(sphere.objectSpecialData)) = radius;

    return sphere;
};

SceneObject createSimpleFlatSurface(SceneEnviroment * sceneEnv, double z_pos)
{
    SceneObject surface;

    surface.parentEnviroment = sceneEnv;

    surface.get_distance = surfaceDestFunction;
    surface.shader = simpleGRAYShader;

    surface.objectSpecialData = malloc(sizeof(double));

    *((double*)(surface.objectSpecialData)) = z_pos;

    return surface;
};
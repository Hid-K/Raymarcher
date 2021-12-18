#include "SceneObjects.h"

double sphereDestFunction(Vec3 point, SceneObject * this)
{
    double res = length(substract(point, this->origin));
    double r = *((double*)(this->objectSpecialData));
    return res - r;
};

Vec3 getSphereNormal(Vec3 point, SceneObject * this)
{
    return normalize(substract(this->origin, point));
};

double cubeDestFunction(Vec3 point, SceneObject * this)
{
    return sqrt(pow(fmax(0, fabs(point.x)-*((double*)this->objectSpecialData)), 2) +
                pow(fmax(0, fabs(point.y)-*((double*)this->objectSpecialData)), 2) +
                pow(fmax(0, fabs(point.z)-*((double*)this->objectSpecialData)), 2));
};

Vec3 getCubeNormal(Vec3 point, SceneObject * this)
{
    Vec3 pointInObjectCentritySpace = substract(this->origin, point);

    double v = *((double*)this->objectSpecialData);

    if(fabs(pointInObjectCentritySpace.x) > v)
            pointInObjectCentritySpace.x  = sign(pointInObjectCentritySpace.x);
    else    pointInObjectCentritySpace.x  = 0;

    if(fabs(pointInObjectCentritySpace.y) > v)
            pointInObjectCentritySpace.y  = sign(pointInObjectCentritySpace.y);
    else    pointInObjectCentritySpace.y  = 0;

    if(fabs(pointInObjectCentritySpace.z) > v)
            pointInObjectCentritySpace.z  = sign(pointInObjectCentritySpace.z);
    else    pointInObjectCentritySpace.z  = 0;

    return normalize(pointInObjectCentritySpace);
};

double surfaceDestFunction(Vec3 point, SceneObject * this)
{
    return fabs(*((double*)(this->objectSpecialData)) - point.z);
};

RGB simpleRaindowShader(CameraRay * ray, SceneObject * this)
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
    };
    return color_spectrum;
};


RGB simpleGRAYShader(CameraRay * ray, SceneObject * this)
{
    RGB color_spectrum = {0.01, 0.01, 0.01};

    if(ray->reflections_count <= 3)
    {
        Vec3 norm = this->getNormal(ray->end, this);

        ray->reflections_count++;
        ray->origin = add(ray->end, multiply(norm, NEAR));
        ray->end = ray->origin;
        ray->direction = getReflection(norm, ray->direction);

        RGB res = {fabs(norm.x), fabs(norm.y), fabs(norm.z)};
        return res;
        // return castRay(ray, this->parentEnviroment);
    }
    return color_spectrum;
};



SceneObject createSimpleSphere(double radius, Vec3 origin, SceneEnviroment * sceneEnv)
{
    SceneObject sphere;

    sphere.parentEnviroment = sceneEnv;

    sphere.get_distance = sphereDestFunction;
    sphere.shader = simpleRaindowShader;
    sphere.rayDeflection = NULL;
    sphere.getNormal = getSphereNormal;
  
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
    surface.rayDeflection = NULL;

    surface.objectSpecialData = malloc(sizeof(double));

    *((double*)(surface.objectSpecialData)) = z_pos;

    return surface;
};

double getMirrorDest(Vec3 point, const SceneObject * this)
{
    return fabs(10 - point.x) - 1;
};

RGB mirrorShader(CameraRay * ray, const SceneObject * this)
{
    // if(ray->reflections_count <= 3)
    // {
    //     Vec3 normal = {10 - ray->end.x, 0, 0};
    //     ray->direction = getReflection(normal, ray->direction);

    //     ray->origin = add(ray->end, multiply(normal, NEAR));
    //     ray->end = ray->origin;

    //     ray->reflections_count++;

    //     return castRay(ray, this->objectSpecialData);
    // } return RGB_WHI;
    return RGB_WHI;
};

SceneObject createMirror(SceneEnviroment * sceneEnv)
{
    SceneObject mirror;

    mirror.parentEnviroment = sceneEnv;

    mirror.get_distance = getMirrorDest;
    mirror.shader = mirrorShader;
    mirror.rayDeflection = NULL;

    return mirror;
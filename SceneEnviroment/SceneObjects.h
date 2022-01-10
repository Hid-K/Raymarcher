#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "SceneEnviroment.h"
#include "../Vec/Vec.h"
#include <stdlib.h>
#include <math.h>

#define CUBE_NORMAL_MACROS(a, v)if(fabs(pointInObjectCentritySpace.x) > v)\
                                pointInObjectCentritySpace.x = sign(pointInObjectCentritySpace.x);\
                                else {pointInObjectCentritySpace.x = 0;

typedef struct SceneObject
{
    Vec3 origin;
    SceneEnviroment * parentEnviroment;
  
    RGB (*shader)(CameraRay * ray, SceneObject * this);
    double (*get_distance)(Vec3 point, SceneObject * this);
    Vec3 (*getNormal)(Vec3 point, SceneObject * this);
  
    void * objectSpecialData;

} SceneObject;

double sphereDestFunction(Vec3 point, SceneObject * this);
Vec3 getSphereNormal(Vec3 point, SceneObject * this);

Vec3 getCubeNormal(Vec3 point, SceneObject * this);
double cubeDestFunction(Vec3 point, SceneObject * this);

double surfaceDestFunction(Vec3 point, SceneObject * this);

RGB simpleRaindowShader(CameraRay * ray, SceneObject * this);
RGB simpleGRAYShader(CameraRay * ray, SceneObject * this);

SceneObject createSimpleSphere(double radius, Vec3 origin, SceneEnviroment * sceneEnv);
SceneObject createSimpleCube(double radius, Vec3 origin, SceneEnviroment * sceneEnv);
SceneObject createSimpleFlatSurface(SceneEnviroment * sceneEnv, double z_pos);

#endif
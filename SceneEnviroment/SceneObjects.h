#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "SceneEnviroment.h"
#include <stdlib.h>

typedef struct SceneObject
{
    Vec3 origin;
    SceneEnviroment * parentEnviroment;
    RGB (*shader)(CameraRay * ray, const SceneObject * this);
    double (*get_distance)(Vec3 point, const SceneObject * this);

    void * objectSpecialData;

} SceneObject;

SceneObject createSimpleSphere(double radius, Vec3 origin, SceneEnviroment * sceneEnv);
SceneObject createSimpleFlatSurface(SceneEnviroment * sceneEnv, double z_pos);

#endif
#ifndef CUSTOM_OBJECTS_H
#define CUSTOM_OBJECTS_H

#include "../../SceneEnviroment/SceneEnviroment.h"
#include "../../SceneEnviroment/SceneObjects.h"

double sphericalRoomDestFunction(Vec3 point, SceneObject * this);
Vec3 getSphericalRoomNormal(Vec3 point, SceneObject * this);
RGB sphericalRoomShader(CameraRay * ray, SceneObject * this);
SceneObject createSimpleSphericalRoom(double radius, Vec3 origin, SceneEnviroment * sceneEnv);

#endif
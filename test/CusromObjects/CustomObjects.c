#include "./CustomObjects.h"

double sphericalRoomDestFunction(Vec3 point, SceneObject * this)
{
    double res = length(substract(point, this->origin));
    return -(res - *((double*)(this->objectSpecialData)));
};

Vec3 getSphericalRoomNormal(Vec3 point, SceneObject * this)
{
    return normalize( substract( point, this->origin ) );
};

RGB sphericalRoomShader(CameraRay * ray, SceneObject * this)
{
    RGB color_specrtum = RGB_WHI;
    return color_specrtum;
};

SceneObject createSimpleSphericalRoom(double radius, Vec3 origin, SceneEnviroment * sceneEnv)
{
    SceneObject room;

    room.parentEnviroment = sceneEnv;

    room.get_distance = sphericalRoomDestFunction;
    room.shader = sphericalRoomShader;
    room.getNormal = getSphericalRoomNormal;

    room.origin = origin;

    room.objectSpecialData = malloc(sizeof(double));

    *((double*)(room.objectSpecialData)) = radius;

    return room;
};
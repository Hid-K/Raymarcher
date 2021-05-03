#include "SceneEnviroment.h"

#include "Vec2.h"
#include "Vec3.h"
#include "RGB.h"
#include <stdlib.h>

#include "SceneObjects.h"

Vec3 light;

void render_frame_of_enviroment_PARALEL(RGB * frame_buffer,
                                size_t buffer_height,
                                size_t buffer_width,
                                SceneEnviroment * enviroment)
{
    light.x = rand()%20;
    light.y = rand()%20;
    light.z = rand()%20;

    double X_scalar = 1;
    double Y_scalar = 1;
    // double fov = 1;
    Vec3 camera_pixel_plane_left_up_render_corner_vector;
    camera_pixel_plane_left_up_render_corner_vector = add(
                                                          add(
                                                                multiply( enviroment->main_camera.up,     ( (double)( buffer_height / Y_scalar ) / 2 ) ),
                                                                multiply( enviroment->main_camera.right, -( (double)( buffer_width / X_scalar )  / 2 ) )
                                                            ),
                                                                    enviroment->main_camera.direction
                                                        );

    // camera_pixel_plane_left_up_render_corner_vector = normalize(camera_pixel_plane_left_up_render_corner_vector);

    Vec3 camera_pixel_plane_right_up_render_corner_vector;
    camera_pixel_plane_right_up_render_corner_vector = add(
                                                          add(
                                                                multiply( enviroment->main_camera.up,     ( (double)( buffer_height / Y_scalar ) /2 ) ),
                                                                multiply( enviroment->main_camera.right,  ( (double)( buffer_width / X_scalar )  /2 ) )
                                                            ),
                                                                    enviroment->main_camera.direction
                                                        );



    Vec3 camera_pixel_plane_right_down_render_corner_vector;
    camera_pixel_plane_right_down_render_corner_vector = add(
                                                            add(
                                                                    multiply( enviroment->main_camera.up,    -( (double)( buffer_height / Y_scalar ) /2 ) ),
                                                                    multiply( enviroment->main_camera.right,  ( (double)( buffer_width / X_scalar )  /2 ) )
                                                                ),
                                                            enviroment->main_camera.direction
                                                        );

    // camera_pixel_plane_right_down_render_corner_vector = normalize(camera_pixel_plane_right_down_render_corner_vector);

    Vec3 frame_buffer_pixel_to_ray_direction_X_ratio = divide(substract(camera_pixel_plane_right_up_render_corner_vector,   camera_pixel_plane_left_up_render_corner_vector),  buffer_width);
    Vec3 frame_buffer_pixel_to_ray_direction_Y_ratio = divide(substract(camera_pixel_plane_right_down_render_corner_vector, camera_pixel_plane_right_up_render_corner_vector), buffer_height);

    // enviroment->ticks_count++;

    for(size_t x = 0; x < buffer_width; ++x)
    {
        for(size_t y = 0; y < buffer_height; ++y)
        {

            Vec3 ray_direction_bias = add(multiply(frame_buffer_pixel_to_ray_direction_X_ratio, buffer_width  - x),
                                          multiply(frame_buffer_pixel_to_ray_direction_Y_ratio, buffer_height - y));
            Vec3 ray_direction = add(camera_pixel_plane_left_up_render_corner_vector, ray_direction_bias);

            frame_buffer[x + y * buffer_width] = castRay(substract(ray_direction, enviroment->main_camera.direction),
                                                        enviroment->main_camera.direction,
                                                        enviroment
                                                        );
        };
    };

    return;
};

void render_frame_of_enviroment_PERSPECTIVE(RGB * frame_buffer,
                                            size_t buffer_height,
                                            size_t buffer_width,
                                            SceneEnviroment * enviroment)
{
    light.x = rand()%20;
    light.y = rand()%20;
    light.z = rand()%20;

    double X_scalar = 1;
    double Y_scalar = 1;
    // double fov = 1;
    Vec3 camera_pixel_plane_left_up_render_corner_vector;
    camera_pixel_plane_left_up_render_corner_vector = add(
                                                          add(
                                                                multiply( enviroment->main_camera.up,     ( (double)( buffer_height / Y_scalar ) / 2 ) ),
                                                                multiply( enviroment->main_camera.right, -( (double)( buffer_width / X_scalar )  / 2 ) )
                                                            ),
                                                                    enviroment->main_camera.direction
                                                        );

    // camera_pixel_plane_left_up_render_corner_vector = normalize(camera_pixel_plane_left_up_render_corner_vector);

    Vec3 camera_pixel_plane_right_up_render_corner_vector;
    camera_pixel_plane_right_up_render_corner_vector = add(
                                                          add(
                                                                multiply( enviroment->main_camera.up,     ( (double)( buffer_height / Y_scalar ) /2 ) ),
                                                                multiply( enviroment->main_camera.right,  ( (double)( buffer_width / X_scalar )  /2 ) )
                                                            ),
                                                                    enviroment->main_camera.direction
                                                        );



    Vec3 camera_pixel_plane_right_down_render_corner_vector;
    camera_pixel_plane_right_down_render_corner_vector = add(
                                                            add(
                                                                    multiply( enviroment->main_camera.up,    -( (double)( buffer_height / Y_scalar ) /2 ) ),
                                                                    multiply( enviroment->main_camera.right,  ( (double)( buffer_width / X_scalar )  /2 ) )
                                                                ),
                                                            enviroment->main_camera.direction
                                                        );

    // camera_pixel_plane_right_down_render_corner_vector = normalize(camera_pixel_plane_right_down_render_corner_vector);

    Vec3 frame_buffer_pixel_to_ray_direction_X_ratio = divide(substract(camera_pixel_plane_right_up_render_corner_vector,   camera_pixel_plane_left_up_render_corner_vector),  buffer_width);
    Vec3 frame_buffer_pixel_to_ray_direction_Y_ratio = divide(substract(camera_pixel_plane_right_down_render_corner_vector, camera_pixel_plane_right_up_render_corner_vector), buffer_height);

    // enviroment->ticks_count++;

    for(size_t x = 0; x < buffer_width; ++x)
    {
        for(size_t y = 0; y < buffer_height; ++y)
        {

            Vec3 ray_direction_bias = add(multiply(frame_buffer_pixel_to_ray_direction_X_ratio, buffer_width  - x),
                                          multiply(frame_buffer_pixel_to_ray_direction_Y_ratio, buffer_height - y));
            Vec3 ray_direction = normalize(add(camera_pixel_plane_left_up_render_corner_vector, ray_direction_bias));

            frame_buffer[x + y * buffer_width] = castRay(enviroment->main_camera.origin,
                                                        ray_direction,
                                                        enviroment
                                                        );
        };
    };

    return;
};

double absd (double a)
{
    if(a < 0){return a * (-1);}
    else return a;
};

RGB castRay(Vec3 origin, Vec3 direction, SceneEnviroment * enviroment)
{

    RGB resultColor = {0,0,0};

    CameraRay currientRay;
    currientRay.origin = origin;

    currientRay.end = origin;

    currientRay.direction = direction;

    currientRay.parentCamera = &enviroment->main_camera;

    for(double rayLength = 0.0; rayLength <= 100;)
    {
        double nearestObjectDest;
        SceneObject * nearectObject = getNearestObject(enviroment, currientRay.end, &nearestObjectDest);
        
        rayLength += nearestObjectDest;

        if(nearestObjectDest <= 0.01)
        {
            return nearectObject->shader(&currientRay, nearectObject);
        };
        Vec3 dCurrPoint = multiply(direction, nearestObjectDest);
        currientRay.end = add(currientRay.end, dCurrPoint);
    };
    return resultColor;
};

SceneObject * getNearestObject(SceneEnviroment * scene, Vec3 point, double * dest)
{
    double currObjectDest       = (*dest = scene->objects[0].get_distance(point, &scene->objects[0]));
    SceneObject * nearestObject = &scene->objects[0];

    for(size_t i = 0; i < 2; ++i)
    {
        if((currObjectDest = scene->objects[i].get_distance(point, &scene->objects[i])) < *dest)
        {
            nearestObject = &scene->objects[i];
            *dest = currObjectDest;
        };
    };

    return nearestObject;
};
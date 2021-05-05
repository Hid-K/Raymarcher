#include "SceneEnviroment.h"

#include "SceneObjects.h"

void render_frame_of_enviroment_PARALEL(RGB * frame_buffer,
                                size_t buffer_height,
                                size_t buffer_width,
                                SceneEnviroment * enviroment)
{
    double X_scalar = 5;
    double Y_scalar = 5;
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
            Vec3 ray_origin = add(camera_pixel_plane_left_up_render_corner_vector, ray_direction_bias);

            CameraRay ray;
            ray.direction = enviroment->main_camera.direction;
            ray.origin = ray_origin;
            ray.end = ray.origin;
            ray.parentCamera = &enviroment->main_camera;
            ray.path_way = 0;
            ray.reflections_count = 0;

            RGB ray_color = castRay(&ray, enviroment);

            normalize_color(&ray_color);

            frame_buffer[x + y * buffer_width] = ray_color;
        };
    };

    return;
};
/*
void render_frame_of_enviroment_PERSPECTIVE(RGB * frame_buffer,
                                            size_t buffer_height,
                                            size_t buffer_width,
                                            SceneEnviroment * enviroment)
{
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

            CameraRay ray;
            ray.direction = normalize(add(camera_pixel_plane_left_up_render_corner_vector, ray_direction_bias));
            ray.origin = enviroment->main_camera.origin;
            ray.end = ray.origin;
            ray.parentCamera = &enviroment->main_camera;
            ray.path_way = 0;
            ray.reflections_count = 0;

            RGB ray_color = castRay(ray, enviroment);

            normalize_color(&ray_color);

            frame_buffer[x + y * buffer_width] = ray_color;
        };
    };

    return;
};
*/

static inline double absd(double a)
{
    /*
                "& 0b0111111111111111111111111111111111111111111111111111111111111111" turns - sign into + in a var.

                Eto pizdec.
    */
    return (double)((long)a & 0b0111111111111111111111111111111111111111111111111111111111111111);
};

inline RGB castRay(CameraRay * ray, SceneEnviroment * enviroment)
{
    RGB resultColor = {0,0,0};

    for(;ray->path_way <= 100.0;)
    {
        double nearestObjectDest;
        SceneObject * nearectObject = getNearestObject(enviroment, ray->end, &nearestObjectDest);

        ray->path_way += nearestObjectDest;

        if( nearestObjectDest <= NEAR &&
            (nearestObjectDest >= 0 || absd(nearestObjectDest) == 0.0) )
        {
            return nearectObject->shader(ray, nearectObject);
        };
        Vec3 dCurrPoint = multiply(ray->direction, nearestObjectDest);
        ray->end = add(ray->end, dCurrPoint);
    };
    return resultColor;
};

inline SceneObject * getNearestObject(SceneEnviroment * scene, Vec3 point, double * dest)
{
    double currObjectDest       = (*dest = scene->objects[0].get_distance(point, &scene->objects[0]));
    SceneObject * nearestObject = &scene->objects[0];

    for(size_t i = 0; i < scene->objects_count; ++i)
    {
        if((currObjectDest = scene->objects[i].get_distance(point, &scene->objects[i])) < *dest)
        {
            nearestObject = &scene->objects[i];
            *dest = currObjectDest;
        };
    };

    return nearestObject;
};
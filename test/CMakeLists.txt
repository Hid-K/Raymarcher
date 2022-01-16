cmake_minimum_required(VERSION 3.0.0)
project(Raymarching VERSION 0.1.0)

set (CMAKE_C_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_compile_options(-lpthread)

add_library(Vec_LIBRARY STATIC
  ../Vec/Vec3/Vec3.h
  ../Vec/Vec3/Vec3.c
  ../Vec/Vec2/Vec2.h
  ../Vec/Vec2/Vec2.c
  ../Vec/Vec.h
)

add_library(SceneEnviroment_LIBRARY STATIC
  ../SceneEnviroment/SceneEnviroment.h
  ../SceneEnviroment/SceneEnviroment.c

  ../SceneEnviroment/SceneObjects.h
  ../SceneEnviroment/SceneObjects.c
)

add_library(MultithreadComputing_LIBRARY STATIC
  ../MultithreadComputing/MultithreadComputing.h
  ../MultithreadComputing/MultithreadComputing.c
)

add_library(RGB_LIBRARY STATIC
  ../RGB/RGB.c
  ../RGB/RGB.h
)

add_library(CUSTOM_OBJECTS STATIC
  ./CusromObjects/CustomObjects.h
  ./CusromObjects/CustomObjects.c
)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} MultithreadComputing_LIBRARY)
target_link_libraries(${PROJECT_NAME} Vec_LIBRARY)
target_link_libraries(${PROJECT_NAME} SceneEnviroment_LIBRARY)
target_link_libraries(${PROJECT_NAME} RGB_LIBRARY)
target_link_libraries(${PROJECT_NAME} CUSTOM_OBJECTS)
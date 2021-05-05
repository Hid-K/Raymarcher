cmake_minimum_required(VERSION 3.0.0)
project(Raymarching VERSION 0.1.0)

set(C_STANDARD C17)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_library(Vec3_LIBRARY STATIC
  Vec/Vec3/Vec3.h
  Vec/Vec3/Vec3.c
)

add_library(Vec2_LIBRARY STATIC
  Vec/Vec2/Vec2.h
  Vec/Vec2/Vec2.c
)

add_library(SceneEnviroment_LIBRARY STATIC
  SceneEnviroment/SceneEnviroment.h
  SceneEnviroment/SceneEnviroment.c

  SceneEnviroment/SceneObjects.h
  SceneEnviroment/SceneObjects.c
)

add_library(RGB_LIBRARY STATIC
  RGB.c
  RGB.h
)

add_executable(${PROJECT_NAME} main.c)


target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Vec3_LIBRARY)
target_link_libraries(${PROJECT_NAME} Vec2_LIBRARY)
target_link_libraries(${PROJECT_NAME} SceneEnviroment_LIBRARY)
target_link_libraries(${PROJECT_NAME} RGB_LIBRARY)
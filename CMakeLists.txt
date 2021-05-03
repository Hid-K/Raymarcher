cmake_minimum_required(VERSION 3.0.0)
project(Raymarching VERSION 0.1.0)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_library(Vec3_LIBRARY STATIC
  Vec3.h
  Vec3.c
)

add_library(Vec2_LIBRARY STATIC
  Vec2.h
  Vec2.c
)

add_library(SceneEnviroment_LIBRARY STATIC
  SceneEnviroment.h
  SceneEnviromentFrameRenderer.c

  SceneObjects.h
  SceneObjects.c
)

add_executable(${PROJECT_NAME} main.c)


target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Vec3_LIBRARY)
target_link_libraries(${PROJECT_NAME} Vec2_LIBRARY)
target_link_libraries(${PROJECT_NAME} SceneEnviroment_LIBRARY)
# Raymarcher

## Build
```
    /snap/bin/cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Debug -H[PATH TO FOLDER]/Raymarcher/test -B[PATH TO FOLDER]/Raymarcher/build -G Ninja
```
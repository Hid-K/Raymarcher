#ifndef RGB_STRUCT_H
#define RGB_STRUCT_H

typedef struct
{
    double r,g,b;
} RGB;

void normalize_color(RGB * color);

RGB add_color(RGB a, RGB b);

static const RGB RGB_RED  = {1,0,0};
static const RGB RGB_GREN = {0,1,0};
static const RGB RGB_BLU  = {0,0,1};
static const RGB RGB_WHI  = {1,1,1};

#endif
#ifndef UTILS_H
#define UTILS_H

/**
 * GLSL-like three dimensional vector
 */
typedef struct vec3
{
    float x;
    float y;
    float z;
} vec3;

/**
 * Color with RGB components
 */
typedef struct Color
{
    float red;
    float green;
    float blue;
} Color;

/**
 * Calculates radian from degree.
 */
double degree_to_radian(double degree);

#endif /* UTILS_H */
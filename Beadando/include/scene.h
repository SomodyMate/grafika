#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model duck;
    Model hare;
    Material material;
    GLuint duck_id;
    GLuint hare_id;
    GLuint Help_menu;
    
    bool Help_visible;
    float rotation;

} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */

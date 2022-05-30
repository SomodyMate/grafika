#include "scene.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <string.h>
#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->duck), "assets/models/duck.obj");
    load_model(&(scene->hare), "assets/models/hare.obj");

    scene->duck_id = load_texture("assets/textures/duck.jpg");
    scene->hare_id = load_texture("assets/textures/hare.jpg");

    scene->Help_menu = load_texture("assets/textures/help_texture.jpg");
    scene->Help_visible = false;

    scene->material.ambient.red = 0.2;
    scene->material.ambient.green = 0.2;
    scene->material.ambient.blue = 0.2;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 100.0;
}

void set_lighting()
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene)
{
    scene->rotation+=1;
}

void render_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    draw_origin();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->hare_id);
    glTranslatef(0, 4, 0);
    glRotatef(90, 0, 0, 1);
    glRotatef(scene->rotation, 0, 0, 1);
    glScalef(0.5, 0.5, 0.5);
    draw_model(&(scene->hare));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->duck_id);
    glTranslatef(0, -4, 0);
    glRotatef(scene->rotation, 0, 0, 1);
    glScalef(0.5, 0.5, 0.5);
    draw_model(&(scene->duck));
    glPopMatrix();
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void Help(GLuint Help_menu) {
        glDisable(GL_CULL_FACE);
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, Help_menu);

        glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3d(-2, 1.5, -3);
        glTexCoord2f(1, 0);
        glVertex3d(2, 1.5, -3);
        glTexCoord2f(1, 1);
        glVertex3d(2, -1.5, -3);
        glTexCoord2f(0, 1);
        glVertex3d(-2, -1.5, -3);
        glEnd();


        glDisable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
}
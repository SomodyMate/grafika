#ifndef GAME_H
#define GAME_H

#include "pong.h"

#include <SDL2/SDL.h>

/**
 * Game state representation
 */
typedef struct Game
{
    SDL_Window* window;
    SDL_GLContext gl_context;
    bool is_running;
    double last_update_time;
    int width;
    int height;
    Pong pong;
} Game;

/**
 * Init the game.
 */
void init_game(Game* game, int width, int height);

/**
 * Free the allocated resources.
 */
void destroy_game(Game* game);

/**
 * Handle the game events.
 */
void handle_game_events(Game* game);

/**
 * Update the state of the game.
 */
void update_game(Game* game);

/**
 * Render the game.
 */
void render_game(Game* game);

/**
 * Initialize the SDL context.
 */
bool init_sdl(Game* game);

/**
 * Initialize the OpenGL.
 */
void init_opengl(Game* game);

#endif /* GAME_H */
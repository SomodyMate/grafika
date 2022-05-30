#ifndef PAD_H
#define PAD_H

enum ColorTheme {
    RED_THEME,
    GREEN_THEME
};

/**
 * Pad position and size
 */
typedef struct Pad
{
    float x;
    float y;
    float width;
    float height;
    float limit;
    float speed;
    enum ColorTheme color_theme;
} Pad;

/**
 * Initialize the pad.
 * @param x horizontal position of the pad
 * @param table_height height of the table in pixels
 * @param color_theme the color theme of the pad
 */
void init_pad(Pad* pad, float x, float table_height, enum ColorTheme color_theme);

/**
 * Move the pad to the given position.
 * @param position required position of the pad
 */
void set_pad_position(Pad* pad, float position);

/**
 * Set the speed of the pad.
 * @param speed required speed of the pad
 */
void set_pad_speed(Pad* pad, float speed);

/**
 * Update the pad after the given period of time.
 */
void update_pad(Pad* pad, double time);

/**
 * Render the pad.
 */
void render_pad(Pad* pad);

#endif /* PAD_H */
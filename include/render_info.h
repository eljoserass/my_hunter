/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** struct to save information of all the game
*/

#ifndef RENDER_INFO_H_
#define RENDER_INFO_H_

#include "image.h"
#include <SFML/Graphics.h>

typedef struct render_info
{
    sfRenderWindow *window;
    sfEvent event;
    sfVector2f pos_click;
    sfClock *clock;
    sfTime time;
    float seconds;
    image_t *duck;
    image_t *back;
    image_t *mouse;
    sfVector2i vector;
    char *inspirig_words[265];
    int killed;
} info;

info *my_init_struct(void);

#endif /* !RENDER_INFO_H_ */

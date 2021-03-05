/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** draw sprites
*/

#include <SFML/Graphics.h>

#include "my_hunter.h"

void draw_game(info *my_info)
{
    sfRenderWindow_drawSprite(my_info->window, my_info->back->sprite, NULL);
    sfRenderWindow_drawSprite(my_info->window, my_info->duck->sprite, NULL);
    sfRenderWindow_drawSprite(my_info->window, my_info->mouse->sprite, NULL);
}
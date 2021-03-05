/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** all the functon to refresh
*/

#include <SFML/Graphics.h>
#include "my_hunter.h"


void draw_cursor(info *my_info)
{
    sfRenderWindow_setMouseCursorVisible(my_info->window, sfFalse);
    move_rect(&my_info->mouse->rect, my_info->mouse->offset, my_info->mouse->max_value);
    sfSprite_setTextureRect(my_info->mouse->sprite, my_info->mouse->rect);
    my_info->mouse->pos.x = my_info->vector.x;
    my_info->mouse->pos.y = my_info->vector.y;
    sfSprite_setPosition(my_info->mouse->sprite, my_info->mouse->pos);
}

int calculate_random_num(int min, int max)
{
    int r_num = rand() % (max + 1 - min) + min;

    return (r_num);
}

void reset_position(info *my_info)
{
    my_info->duck->pos.x = -140;
    my_info->duck->pos.y = calculate_random_num(10, 450);
}

void refresh_game(info *my_info)
{
    my_info->time = sfClock_getElapsedTime(my_info->clock);
    my_info->seconds = my_info->time.microseconds / 1000000.0;
    if (my_info->seconds > 0.1) {
        draw_cursor(my_info);
        move_rect(&my_info->duck->rect, my_info->duck->offset, my_info->duck->max_value);
        sfSprite_setTextureRect(my_info->duck->sprite, my_info->duck->rect);
        my_info->duck->pos.x += calculate_random_num(20, 40);
        sfSprite_setPosition(my_info->duck->sprite, my_info->duck->pos);
        sfClock_restart(my_info->clock);
    }
    if (my_info->duck->pos.x >= 800) {
        reset_position(my_info);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}
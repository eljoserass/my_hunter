/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** functions related to handling events
*/

#include <SFML/Graphics.h>
#include "my_hunter.h"

void my_handle_event(info *my_info)
{
    my_info->vector = sfMouse_getPositionRenderWindow(my_info->window);

    while (sfRenderWindow_pollEvent(my_info->window, &my_info->event)) {
        if (my_info->event.type == sfEvtClosed)
                sfRenderWindow_close(my_info->window);
        
        if (my_info->event.type == sfEvtMouseButtonPressed) {
            my_info->pos_click.x = my_info->vector.x;
            my_info->pos_click.y = my_info->vector.y;
            my_kill_duck(my_info);
        }
    }   
}

void my_kill_duck(info *my_info)
{
    int min_size_x = my_info->duck->pos.x + 20;
    int max_size_x = my_info->duck->pos.x + 100;
    int min_size_y = my_info->duck->pos.y + 20;
    int max_size_y = my_info->duck->pos.y + 100;

    if ((my_info->pos_click.x >= min_size_x) && 
    (my_info->pos_click.x <= max_size_x) && 
    (my_info->pos_click.y >= min_size_y) && 
    (my_info->pos_click.y <= max_size_y)) {
        reset_position(my_info);
        my_info->killed += 1;
    }
}
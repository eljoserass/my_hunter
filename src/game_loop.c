/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** in this file, the game loop lives
*/

#include <SFML/Graphics.h>
#include <stdio.h>

#include "my_hunter.h"

void destroy_everything(info *my_info)
{
    sfSprite_destroy(my_info->duck->sprite);
    sfTexture_destroy(my_info->duck->texture);
    sfRenderWindow_destroy(my_info->window);
}

void print_end_mesage(info *my_info)
{
    my_putstr("you killed ");
    my_put_nbr(my_info->killed);
    my_putstr(" monsters at cold blood\n----------------------\n");
    my_putstr(my_info->inspirig_words[calculate_random_num(0,16)]);
    my_putchar('\n');
}


int my_do_game_loop(void)
{
    info *my_info = my_init_struct();

    if (my_info == NULL)
        return (84);
     
    while (sfRenderWindow_isOpen(my_info->window)) {
        sfRenderWindow_clear(my_info->window, sfBlack);
        my_handle_event(my_info);
        refresh_game(my_info);
        draw_game(my_info);
        sfRenderWindow_display(my_info->window);
    }
    destroy_everything(my_info);
    print_end_mesage(my_info);
    return (0);
}
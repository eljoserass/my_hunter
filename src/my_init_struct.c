/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** initialize structure
*/

#include "my_hunter.h"

info *my_init_struct_one(void)
{
    info *my_info = malloc(sizeof(info));
    
    if (my_info == NULL)
        return (NULL);

    my_info->window = open_window(800, 600, "madafreakingame");
    my_info->clock = sfClock_create();
    my_info->time = sfClock_getElapsedTime(my_info->clock);
    my_info->duck = init_image("images/Flight.png", 
    (sfIntRect){0 , 0, 150, 150}, (sfVector2f){0, 0}, 1200);
    my_info->pos_click.x = 0;
    my_info->pos_click.y = 0;
    my_info->back = init_image("images/background.png",
    (sfIntRect){0, 0, 800, 600}, (sfVector2f){0, 0}, 800);

    if (!my_info->duck || !my_info->back)
        return (NULL);
    return (my_info);
}

info *my_init_struct_two(void)
{
    info *my_info = my_init_struct_one();

    my_info->inspirig_words[0] = "U suck haha";
    my_info->inspirig_words[1] = "not bad kid";
    my_info->inspirig_words[2] = "kinda trash but ok";
    my_info->inspirig_words[3] = "that's all what you got?";
    my_info->inspirig_words[4] = "disapointing.";
    my_info->inspirig_words[5] = "i bet you your grandma can do it better";
    my_info->inspirig_words[6] = 
    "a great power comes with a geat responsability";
    my_info->inspirig_words[7] = "you basically beat the game bro";
    my_info->inspirig_words[8] = "follow on ig: jose11antonio";
    my_info->inspirig_words[9] = "it's done bro, i have the high ground";
    my_info->inspirig_words[10] = "i hate sand";
    my_info->inspirig_words[11] = "i am inevitable";
    my_info->inspirig_words[12] =
    "what are you doing here you don't have stuff to do?";
    my_info->inspirig_words[13] = "you killed the younglings";

    return (my_info);
}

info *my_init_struct(void)
{
    info *my_info = my_init_struct_two();

    my_info->killed = 0;
    my_info->inspirig_words[14] =
    "the monsters were like: i don't want to go mr stark";
    my_info->inspirig_words[15] = "killer";
    my_info->inspirig_words[16] = 
    "why i'm spending so much time writing this haha, btw gg bro";
    my_info->mouse = init_image("images/hand_and_ring.png",
    (sfIntRect){0, 0, 128, 128}, (sfVector2f){0, 0}, 1664);
    my_info->vector.x = 0;
    my_info->vector.y = 0;

    return (my_info);
}



image_t *init_image(char *path, sfIntRect rect, sfVector2f pos, int max_value)
{
    image_t *image = malloc(sizeof(image_t));
    
    if (image == NULL)
        return (NULL);

    image->texture = sfTexture_createFromFile(path, NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTextureRect(image->sprite, image->rect);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    image->rect = rect;
    image->pos = pos;
    image->offset = rect.width;
    image->max_value = max_value;
    return (image);
}
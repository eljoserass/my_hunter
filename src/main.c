/*
** EPITECH PROJECT, 2020
** main
** File description:
** MAIN
*/

#include <SFML/Graphics.h>
#include "my_hunter.h"

void print_usage(void)
{
    my_putstr("WELLCOME TO THE GAME\n\n");
    my_putstr("HISTORY:\n");
    my_putstr("You are in the medieval age..\n");
    my_putstr("A rock falling from the sky maked some weird things to happend.\n");
    my_putstr("It had inside a bunch of weird, dinasour size, eggs.\n");
    my_putstr("Your community didn't care about it, until thet start to crack.\n");
    my_putstr("A bunch of weird, one eyed, flying creatures started to rise.\n");
    my_putstr("They started killing every live thing in their way, and you and your loved ones are in their way\n");
    my_putstr("You have powers to magically make them disapear with the power of your mind (or your hand by clicking)\n");
    my_putstr("\n\nHOW TO USE IT:\n");
    my_putstr("To enter in the life of this guy, execute the binary (the one in green) with ./ before the name. Ex: ./binary\n");
    my_putstr("To exit simply click the 'x' in your window\n");
    my_putstr("After you will see how many you kill\n");
    my_putstr("Hope you enjoy it :)\n");
}

int my_strcmp(char *one, char *two)
{
    int i = 0;

    while (one[i] != '\0') {
        if (one[i] != two[i])
            return (0);
        else
            i++;
    }
    return (1);
}

int check_arguments(int ac, char **av)
{
    if ((ac == 2) && (my_strcmp("-h", av[1]) == 1)) {
        print_usage();
        return (0);
    }
    if ((ac == 2) && (my_strcmp("-h", av[1]) == 0) || (ac > 2)) {
        my_putstr("-h for usage\n");
        return (84);
    }
}

int main(int ac, char **av)
{
    int output = check_arguments(ac, av);

    if (output == 0)
        return (0);
    if (output == 84)
        return (84);
    if (my_do_game_loop() == 84) {
        my_putstr("-h for usage\n");
        return (84);
    }
    return (0);
}
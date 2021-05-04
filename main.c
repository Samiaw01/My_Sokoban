/*
** EPITECH PROJECT, 2021
** main
** File description:
** main sokoban
*/

#include "my.h"

int main(int argc, char **argv)
{
    char *map = read_map(argv[1]);
    coords player = {0, 0, 0, 0};
    map_i items = {0, 0, 0, 0};

    if (argc != 2)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        help();
        return (0);
    }
    if (verify_map(map, &items) == 84) {
        return (84);
    }
    targ *o = malloc(sizeof(targ) * items.storage);
    display_map(map, player, o, items);
    return (0);
}
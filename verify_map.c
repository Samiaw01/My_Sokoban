/*
** EPITECH PROJECT, 2021
** main
** File description:
** main sokoban
*/

#include "my.h"

int verify_map(char *map, map_i *items)
{
    for (int i = 0; map[i]; i++) {
        if (map[i] == 'P')
            items->player = items->player + 1;
        if (map[i] == 'X')
            items->boxes = items->boxes + 1;
        if (map[i] == '#')
            items->walls = items->walls + 1;
        if (map[i] == 'O')
            items->storage = items->storage + 1;
        if (map[i] != 'O' && map[i] != 'P' && map[i] != 'X' \
        && map[i] != '#' && map[i] != ' ' && map[i] != '\n')
            return (84);
    }
    if (items->player != 1 || items->boxes == 0 || \
    items->walls == 0 || items->storage == 0 \
    || items->boxes != items->storage)
        return (84);
    return (0);
}

coords detect_player(char **map, coords player)
{
    player.x = 0;
    player.y = 0;
    player.x_temp = 0;

    for (; map[player.y]; player.y++) {
        for (; map[player.y][player.x_temp] && \
        map[player.y][player.x_temp] != 'P'; player.x_temp++);
        if (map[player.y][player.x_temp] == 'P')
            break;
        else
            player.x_temp = 0;
    }
    map[player.y][player.x_temp] = ' ';
    return (player);
}

void print_map(char **new_map)
{
    int i = 0;

    for (; new_map[i]; i++) {
        printw("%s\n", new_map[i]);
    }
}

coords detect_walls(char **map, coords player, int result)
{
    if (map[player.y][player.x_temp] == '#' || \
    map[player.y][player.x_temp] == 'X') {
        switch (result) {
        case 66:
            player.y -= 1;
            break;
        case 65:
            player.y += 1;
            break;
        case 67:
            player.x_temp -= 1;
            break;
        case 68:
            player.x_temp += 1;
            break;
        }
    }
    return (player);
}
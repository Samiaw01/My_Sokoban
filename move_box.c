/*
** EPITECH PROJECT, 2021
** main
** File description:
** main sokoban
*/

#include "my.h"

void one(char **map, coords *player);

void two(char **map, coords *player);

void tree(char **map, coords *player);

void four(char **map, coords *player);

char **move_box(char **map, coords *player, int result)
{
    if (map[player->y][player->x_temp] == 'X') {
        switch (result) {
        case 66:
            one(map, player);
            break;
        case 65:
            two(map, player);
            break;
        case 67:
            tree(map, player);
            break;
        case 68:
            four(map, player);
            break;
        }
    }
    return (map);
}

void one(char **map, coords *player)
{
    if (map[player->y + 1][player->x_temp] != '#' && \
    map[player->y + 1][player->x_temp] != 'X') {
        map[player->y][player->x_temp] = ' ';
        map[player->y + 1][player->x_temp] = 'X';
    }
}

void two(char **map, coords *player)
{
    if (map[player->y - 1][player->x_temp] != '#' && \
    map[player->y - 1][player->x_temp] != 'X') {
        map[player->y][player->x_temp] = ' ';
        map[player->y - 1][player->x_temp] = 'X';
    }
}

void tree(char **map, coords *player)
{
    if (map[player->y][player->x_temp + 1] != '#' && \
    map[player->y][player->x_temp + 1] != 'X') {
        map[player->y][player->x_temp] = ' ';
        map[player->y][player->x_temp + 1] = 'X';
    }
}

void four(char **map, coords *player)
{
    if (map[player->y][player->x_temp - 1] != '#' && \
    map[player->y][player->x_temp - 1] != 'X') {
        map[player->y][player->x_temp] = ' ';
        map[player->y][player->x_temp - 1] = 'X';
    }
}
/*
** EPITECH PROJECT, 2021
** main
** File description:
** main sokoban
*/

#include "my.h"

char *read_map(char const *str)
{
    struct stat sb;
    int u;
    int verifo = 0;
    char *buff;

    verifo = open(str, O_RDONLY);
    stat(str, &sb);
    u = sb.st_size;
    buff = malloc(sizeof(char) * (u + 1));
    read(verifo, buff, u);
    buff[u] = '\0';
    close(verifo);
    return (buff);
}

void pos_o(map_i items, targ *o, char **map)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (i < items.storage) {
        while (map[y][x]) {
            if (map[y][x] == 'O') {
                o[i].x = x;
                o[i].y = y;
                i++;
            }
            x++;
        }
        y++;
        x = 0;
    }
}

char **display_o(char **map, targ *o, map_i items)
{
    int i = 0;
    while (i < items.storage) {
        if (map[o[i].y][o[i].x] == ' ')
            map[o[i].y][o[i].x] = 'O';
        i++;
    }
    return (map);
}
/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** aa
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <ncurses.h>
#include "lib/my/my.h"

typedef struct coords {
    int x_temp;
    int x;
    int y;
    char **new_maps;
} coords;

typedef struct targ {
    int x;
    int y;
} targ;

typedef struct map {
    int player;
    int boxes;
    int walls;
    int storage;
} map_i;

char **display_o(char **map, targ *o, map_i items);
void pos_o(map_i items, targ *o, char **map);
int verif_o(char **map);
char **move_box(char **map, coords *player, int result);
void print_map(char **new_map);
coords detect_walls(char **map, coords walls, int result);
void display_map(char *map, coords player, targ *o, map_i items);
void help(void);
void print_walls(int max_x, int max_y);
int move_player(int *x, int *y, int result);
char *read_map(char const *str);
int verify_map(char *map, map_i *items);
coords detect_player(char **map, coords player);
char **my_str_t_w_a(char *str, char const *sep);
int ma(char const *str, char const *sep, int *size);
int match(char const *str, char const *sep, int size);
char **set_tab(char **dest, char *src, int *size, char const *sep);

#endif /* !MY_H_ */
/*
** EPITECH PROJECT, 2021
** main
** File description:
** main sokoban
*/

#include "my.h"

char **news_map(char **new_map, coords *player, int result);

coords fi(char *map, coords player);

void display_map(char *map, coords player, targ *o, map_i items)
{
    int result = 0;
    player.new_maps = my_str_t_w_a(map, "\n");
    initscr();
    noecho();
    curs_set(FALSE);
    player = detect_player(player.new_maps, player);
    pos_o(items, o, player.new_maps);

    while (verif_o(player.new_maps) == 1) {
        if (result == ' ')
            player = fi(map, player);
        player.new_maps = display_o(player.new_maps, o, items);
        news_map(player.new_maps, &player, result);
        player = detect_walls(player.new_maps, player, result);
        mvprintw(player.y, player.x_temp, "P");
        refresh();
        result = getch();
        move_player(&player.x_temp, &player.y, result);
    }
    endwin();
}

int verif_o(char **map)
{
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == 'O')
            return (1);
        }
    }
    return (0);
}

char **news_map(char **new_map, coords *player, int result)
{
    clear();
    move(0, 0);
    new_map = move_box(new_map, player, result);
    print_map(new_map);
    return (new_map);
}

coords fi(char *map, coords player)
{
    for (int i = 0; player.new_maps[i]; i++) {
        free(player.new_maps[i]);
    }
    player = (coords){0, 0, 0, 0};
    player.new_maps = my_str_t_w_a(map, "\n");
    player = detect_player(player.new_maps, player);
    return (player);
}
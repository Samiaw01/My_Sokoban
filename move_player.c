/*
** EPITECH PROJECT, 2021
** main
** File description:
** main sokoban
*/

#include "my.h"

int move_player(int *x, int *y, int result)
{
    switch (result)
    {
    case 66:
        *y += 1;
        break;
    case 65:
        *y -= 1;
        break;
    case 67:
        *x += 1;
        break;
    case 68:
        *x -= 1;
        break;
    }
    return (result);
}
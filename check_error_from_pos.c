/*
** EPITECH PROJECT, 2023
** test
** File description:
** qds
*/

#include "include/mynavy.h"

int check_pos(char **pos)
{
    if (pos[3] != NULL)
        return 84;
    if (pos[1][2] == '\0') {
        if (pos[1][0] < 'A' || pos[1][0] > 'H')
            return 84;
        if (pos[1][1] < '1' || pos[1][1] > '8')
            return 84;
    }
    if (pos[2][3] == '\0') {
        if (pos[2][0] < 'A' || pos[2][0] > 'H')
            return 84;
        if (pos[2][1] < '1' || pos[2][1] > '8')
            return 84;
    }
    if ((pos[1][2] != '\0') || (pos[2][3] != '\0'))
        return 84;
    return 0;
}

int char_to_int(char c)
{
    return c - '0';
}

int check_sizeofnavy(char **pos)
{
    int x = 0;
    int y = 0;
    int res = 0;
    int size = pos[0][0] - '0';
    if (pos[1][0] == pos[2][0]) {
        x = pos[1][1] - '0';
        y = pos[2][1] - '0';
    } else {
        x = pos[1][0] - '@';
        y = pos[2][0] - '@';
    }
    res = y - x + 1;
    if (res != size)
        return 84;
    return 0;
}

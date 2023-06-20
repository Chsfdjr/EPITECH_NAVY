/*
** EPITECH PROJECT, 2023
** put position
** File description:
** put position
*/

#include "include/mynavy.h"

void init_tab(char tab[8][8])
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tab[i][j] = '.';
        }
    }
}

void parse_line(char *line, Coordinates *coordinates)
{
    int i = 0, j = 0;
    coordinates->length = 0;
    while (line[i] != ':') {
        coordinates->length = coordinates->length * 10 + (line[i] - '0');
        i++;
    }
    i++;
    j = 0;
    while (line[i] != ':') {
        coordinates->firstSquare[j] = line[i];
        i++;
        j++;
    }
    i++;
    j = 0;
    while (line[i] != '\n' && line[i] != '\0') {
        coordinates->lastSquare[j] = line[i];
        i++;
        j++;
    }
}

int get_firsty(char *firstSquare)
{
    return firstSquare[0] - 'A';
}

int get_firstx(char *firstSquare)
{
    return firstSquare[1] - '0' - 1;
}

int get_lasty(char *lastSquare)
{
    return lastSquare[0] - 'A';
}

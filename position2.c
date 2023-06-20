/*
** EPITECH PROJECT, 2023
** position2
** File description:
** position2
*/

#include "include/mynavy.h"

int get_lastx(char *lastSquare)
{
    return lastSquare[1] - '0' - 1;
}

void update_y(char tab[8][8], Coordinates coordinates)
{
    int firstY = get_firsty(coordinates.firstSquare);
    int lastY = get_lasty(coordinates.lastSquare);
    if (firstY > lastY) {
        int temp = firstY;
        firstY = lastY;
        lastY = temp;
    }
    for (int i = firstY; i <= lastY; i++) {
        tab[get_firstx(coordinates.firstSquare)][i] = coordinates.length + '0';
    }
}

void update_x(char tab[8][8], Coordinates coordinates)
{
    int firstX = get_firstx(coordinates.firstSquare);
    int lastX = get_lastx(coordinates.lastSquare);
    if (firstX > lastX) {
        int temp = firstX;
        firstX = lastX;
        lastX = temp;
    }
    for (int i = firstX; i <= lastX; i++) {
        tab[i][get_firsty(coordinates.firstSquare)] = coordinates.length + '0';
    }
}

void updatetab(char tab[8][8], Coordinates coordinates)
{
    if (get_firstx(coordinates.firstSquare) ==
    get_lastx(coordinates.lastSquare)) {
        update_y(tab, coordinates);
    } else if (get_firsty(coordinates.firstSquare) ==
    get_lasty(coordinates.lastSquare)) {
        update_x(tab, coordinates);
    }
}

void read_file(FILE *file, char tab[8][8])
{
    size_t len = 0;
    char *line = NULL;
    Coordinates coordinates;

    while (getline(&line, &len, file) != -1) {
        parse_line(line, &coordinates);
        updatetab(tab, coordinates);
    }
    free(line);
}

/*
** EPITECH PROJECT, 2023
** test
** File description:
** qds
*/

#include "include/mynavy.h"

char **put_in_map(char *buffer, ssize_t nb)
{
    char **map = NULL;
    int y = 0;
    int c_elem = 0;
    c_elem = count_elem(buffer);
    if (c_elem != 2)
        return map;
    map = createmapfrombuffer(buffer, nb);
    return map;
}

int count_largeur(char *buffer)
{
    int largeur = 0;
    int i = 0;

    for (; buffer[i] != ':' ; i++)
        largeur++;
    return largeur;
}

int count_elem(char *buffer)
{
    int largeur = 0;
    int i = 0;

    for (; buffer[i] != '\0' ; i++) {
        if (buffer[i] == ':')
            largeur++;
    }
    return largeur;
}

void *makepartofbuffer(char *map, char *buffer, int j)
{
    int i = 0;

    while (buffer[i] != ':') {
            map[i] = buffer[i];
            j++;
            i++;
    }
    map[i] = '\0';
}

char **createmapfrombuffer(char *buffer, ssize_t y)
{
    char **map = NULL;
    int x = 0;

    map = malloc(sizeof(char *) * (y + 1));
    map[y] = NULL;
    for (int i = 0 ; i < y ; i++) {
        x = count_largeur(buffer);
        map[i] = malloc(sizeof(char) * (x + 1));
        makepartofbuffer(map[i], buffer, x);
        buffer = buffer + (x + 1);
    }
    return map;
}

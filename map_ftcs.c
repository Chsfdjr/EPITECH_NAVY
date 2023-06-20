/*
** EPITECH PROJECT, 2023
** main part 2
** File description:
** main
*/

#include "include/mynavy.h"

void init_map(char map[8][8])
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
    }
}

void void_map(char map[8][8])
{
    my_printf("enemy's positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0 ; i < 8 ; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            my_printf("%c ", map[i][j]);
        }
        my_printf("\n");
    }
}

void print_tab(char tab[8][8])
{
    my_printf("my positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++) {
            my_printf("%c ", tab[i][j]);
        }
        my_printf("\n");
    }
}

void map_ftcs2(char *av)
{
    char tab[8][8];
    FILE *file;

    file = fopen(av, "r");
    init_tab(tab);
    read_file(file, tab);
    print_tab(tab);
    fclose(file);
}

char (*map_ftcs(char *av))[8] {
    char (*tab)[8] = malloc(sizeof(char[8][8]));
    FILE *file;

    file = fopen(av, "r");
    init_tab(tab);
    read_file(file, tab);
    fclose(file);
    return tab;
}

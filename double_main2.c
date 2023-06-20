/*
** EPITECH PROJECT, 2023
** doublemain
** File description:
** main
*/

#include "include/mynavy.h"

int main_ac3(int ac, char **av, char map[8][8])
{
    char *tab;
    char map_ene[8][8];
    int check = 0;

    varnavy->navy_p1 = 0;
    varnavy->navy_p2 = 0;
    tab = av[2];
    check = main_3(ac, av);
    if (check == 84)
        return 84;
    remplirmap(map, map_ene, tab);
    map_ftcs2(tab);
    my_printf("\n");
    void_map(map);
    if (navy_p2(varnavy, map, map_ene) == 1)
        return 1;
    else
        return 0;
}

int main(int ac, char **av)
{
    int check = 0;
    char map[8][8];
    varnavy = malloc(sizeof(navy));

    init_map(map);
    if (ac == 2) {
        check = main_ac2(ac, av, map);
        return check;
    } if (ac == 3) {
        check = main_ac3(ac, av, map);
        return check;
    } else {
        write(2, "input error : try -h\n", 22);
        return 84;
    }
    return 0;
}

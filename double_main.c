/*
** EPITECH PROJECT, 2023
** main part 2
** File description:
** main
*/

#include "include/mynavy.h"

navy *varnavy;

navy *remplirnavy(navy *varnavy, int pid1, int pid2)
{
    varnavy->pid_p1 = pid1;
    varnavy->pid_p2 = pid2;
    varnavy->player = 1;
    varnavy->letter = 64;
    varnavy->number = 0;
    return varnavy;
}

int main_2(int ac, char **av)
{
    if (my_strcmp(av[1], "-h") == 0) {
            navy_h();
            return 1;
    }
    if (checkfile(av[1]) == 84) {
        write(2, "Invalid file\n", 13);
        return 84;
    }
    if (check_pid(ac, av) == 84) {
        write(2, "Invalid file\n", 13);
        return 84;
    }
    return 0;
}

int main_3(int ac, char **av)
{
    if (checkfile(av[2]) == 84) {
        write(2, "Invalid file\n", 13);
        return 84;
    }
    if (check_pid(ac, av) == 84) {
        write(2, "Invalid player_pid\n", 18);
        return 84;
    }
    varnavy = remplirnavy(varnavy, av_to_int(av[1]), getpid());
    return 0;
}

void remplirmap(char map[8][8], char map_ene[8][8], char *tab)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            map_ene[i][j] = map_ftcs(tab)[i][j];
    }
}

int main_ac2(int ac, char **av, char map[8][8])
{
    char *tab;
    char map_ene[8][8];
    int check = 0;

    varnavy->navy_p1 = 0;
    varnavy->navy_p2 = 0;
    check = main_2(ac, av);
    if (check == 1)
        return 0;
    if (check == 84)
        return 84;
    tab = av[1];
    remplirmap(map, map_ene, tab);
    map_ftcs2(tab);
    my_printf("\n");
    void_map(map);
    if (navy_p1(varnavy, map, map_ene) == 1)
        return 1;
    else
        return 0;
}

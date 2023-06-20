/*
** EPITECH PROJECT, 2023
** test
** File description:
** qds
*/

#include "include/mynavy.h"

char **hitmissedftc_receive(char his_map[8][8], int player)
{
    struct sigaction act;
    initsignal_forhm(act);
    if (varnavy->receivesignal == 2) {
        his_map[varnavy->number - 1][varnavy->letter - 'A'] = 'x';
        my_printf("%c%d: hit\n\n", varnavy->letter, varnavy->number);
        if (player == 1)
            varnavy->navy_p1++;
        else
            varnavy->navy_p2++;
    }
    if (varnavy->receivesignal == 1) {
        his_map[varnavy->number - 1][varnavy->letter - 'A'] = 'x';
        my_printf("%c%d: missed\n\n", varnavy->letter, varnavy->number);
    }
    if (varnavy->receivesignal == 0) {
        his_map[varnavy->number - 1][varnavy->letter - 'A'] = 'o';
        my_printf("%c%d: missed\n\n", varnavy->letter, varnavy->number);
    }
    varnavy->receivesignal = 0;
    return his_map;
}

char **hitmissedftc_push(int pid, char my_map[8][8], int player)
{
    if (my_map[varnavy->number - 1][varnavy->letter - 'A'] == 'x') {
        my_printf("%c%d: missed\n\n", varnavy->letter, varnavy->number);
        kill_ftc(pid, SIGUSR1, SIGUSR2);
        return my_map;
    } if ((my_map[varnavy->number - 1][varnavy->letter - 'A'] == '.') ||
        (my_map[varnavy->number - 1][varnavy->letter - 'A'] == 'o')) {
        my_map[varnavy->number - 1][varnavy->letter - 'A'] = 'o';
        my_printf("%c%d: missed\n\n", varnavy->letter, varnavy->number);
        kill_ftc(pid, SIGUSR2, SIGUSR2);
        return my_map;
    } if (my_map[varnavy->number - 1][varnavy->letter - 'A'] != '.') {
        my_map[varnavy->number - 1][varnavy->letter - 'A'] = 'x';
        my_printf("%c%d: hit\n\n", varnavy->letter, varnavy->number);
        kill_ftc(pid, SIGUSR1, SIGUSR1);
        if (player == 1)
            varnavy->navy_p2++;
        else
            varnavy->navy_p1++;
        return my_map;
    } return my_map;
}

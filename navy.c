/*
** EPITECH PROJECT, 2023
** test
** File description:
** qds
*/

#include "include/mynavy.h"

void checkbuffer(char *buf)
{
    if (((buf[0] < 'A') || (buf[0] > 'H')) ||
    ((buf[1] < '1') || (buf[1] > '8')) ) {
        my_printf("wrong position\n");
        my_printf("attack: ");
        read(0, buf, 3);
        checkbuffer(buf);
    }
}

int winner_cond(int player, char my_map[8][8], char his_map[8][8])
{
    if ((player == 1 && varnavy->navy_p1 == 14) ||
        (player == 2 && varnavy->navy_p2 == 14)) {
        my_printf("\nI won\n\n");
        return 0;
    }
    if ((player == 2 && varnavy->navy_p1 == 14) ||
        (player == 1 && varnavy->navy_p2 == 14)) {
        my_printf("\nEnemy won\n\n");
        return 1;
    } else {
        if (player == 1)
            navy_p1(varnavy, my_map, his_map);
        else
            navy_p2(varnavy, my_map, his_map);
    }
}

void separate_navyftc(char my_map[8][8], char his_map[8][8], int p1, int p2)
{
    char buf[3];

    my_printf("\nattack: ");
    read(0, buf, 3);
    checkbuffer(buf);
    if (p1 == 1)
        attack_navy(buf, varnavy->pid_p2);
    else
        attack_navy(buf, varnavy->pid_p1);
    varnavy->letter = buf[0];
    varnavy->number = buf[1] - 48;
    my_map = hitmissedftc_receive(my_map, p1);
    print_tab(his_map);
    my_printf("\n");
    void_map(my_map);
    varnavy->letter = buf[0];
    varnavy->number = buf[1] - 48;
    varnavy->player = p2;
}

int navy_p1(navy *varnavy, char my_map[8][8], char his_map[8][8])
{
    struct sigaction act;
    initsignal(act);
    while (varnavy->player == 1)
        separate_navyftc(my_map, his_map, 1, 2);
    usleep(1000);
    if (varnavy->navy_p1 == 14) {
        my_printf("\nI won\n");
        return 0;
    }
    while (varnavy->player == 2) {
        my_printf("\nwaiting for enemy's attack...\n", varnavy->pid_p2);
        varnavy = receive_attack(varnavy->pid_p2, 1);
        his_map = hitmissedftc_push(varnavy->pid_p2, his_map, 1);
        print_tab(his_map);
        my_printf("\n");
        void_map(my_map);
    }
    return winner_cond(1, my_map, his_map);
}

int navy_p2(navy *varnavy, char my_map[8][8], char his_map[8][8])
{
    struct sigaction act;
    initsignal(act);
    while (varnavy->player == 2)
        separate_navyftc(my_map, his_map, 2, 1);
    usleep(1000);
    if (varnavy->navy_p1 == 14) {
        my_printf("\nI won\n");
        return 0;
    }
    while (varnavy->player == 1) {
        my_printf("\nwaiting for enemy's attack...\n", varnavy->pid_p1);
        varnavy = receive_attack(varnavy->pid_p1, 2);
        his_map = hitmissedftc_push(varnavy->pid_p1, his_map, 2);
        print_tab(his_map);
        my_printf("\n");
        void_map(my_map);
    }
    return winner_cond(2, my_map, his_map);
}

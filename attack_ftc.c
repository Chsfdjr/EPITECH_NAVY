/*
** EPITECH PROJECT, 2023
** test
** File description:
** qds
*/

#include "include/mynavy.h"

void initsignal_forhm(struct sigaction act)
{
    act.sa_sigaction = &hit_or_missed;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    waitsignal(1);
}

void kill_ftc(int pid, int SIG1, int SIG2)
{
    kill(pid, SIG1);
    usleep(1000);
    kill(pid, SIG2);
    usleep(1000);
}

void attack_navy(char *buf, int pid)
{
    int temp = 0;
    for (int i = 0 ; i < 8 ; i++) {
        if (temp < buf[0] - 64)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        temp++;
        usleep(1000);
    }
    temp = 0;
    for (int d = 0 ; d < 8 ; d++) {
        if (temp < buf[1] - '0')
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        temp++;
        usleep(1000);
    }
}

void waitsignal(int time)
{
    int i = 0;
    int signal = 0;

    while (i < time) {
        if (signal == -1) {
            i++;
            signal = 0;
        }
        signal = pause();
    }
}

navy *receive_attack(int pid, int player)
{
    varnavy->letter = 64;
    varnavy->number = 0;
    struct sigaction act;
    act.sa_sigaction = &signal_from_attack;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    waitsignal(15);
    kill(pid, SIGUSR1);
    usleep(1000);
    varnavy->player = player;
    varnavy->receivesignal = 0;
}

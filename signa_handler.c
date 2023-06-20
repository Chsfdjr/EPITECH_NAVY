/*
** EPITECH PROJECT, 2023
** test
** File description:
** qds
*/

#include "include/mynavy.h"

void initsignal(struct sigaction act)
{
    act.sa_sigaction = &signal_from_attack;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
}

int signal_from_attack(int signo, void *ptr)
{
    int sigu2 = varnavy->receivesignal;

    if (signo == SIGUSR2)
        sigu2++;
    if (signo == SIGUSR1) {
        if ((sigu2 > 0) || (varnavy->letter == 'H')) {
            varnavy->number++;
            return 0;
        }
        if ((varnavy->letter >= 64 && sigu2 == 0) ||
            (varnavy->letter < 'H' && sigu2 == 0)) {
            varnavy->letter += 1;
            return 0;
        }
    }
    varnavy->receivesignal = sigu2;
    return 0;
}

int hit_or_missed(int signo, void *ptr)
{
    int sigu1 = varnavy->receivesignal;

    if (signo == SIGUSR1)
        sigu1++;
    varnavy->receivesignal = sigu1;
    return 0;
}

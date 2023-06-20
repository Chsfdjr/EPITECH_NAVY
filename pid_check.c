/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "./include/mynavy.h"

void init_signal_pid(struct sigaction act)
{
    act.sa_sigaction = &signal_connection;
    act.sa_flags = SA_SIGINFO;
    sigemptyset(&act.sa_mask);
    sigaction(SIGUSR1, &act, NULL);
}

int signal_connection(int signo, siginfo_t *pid1_oe, void *ptr)
{
    if (signo == SIGUSR1) {
        my_printf("\nenemy connected\n\n");
        varnavy->pid_p2 = pid1_oe->si_pid;
        varnavy->player = 1;
    }
}

int check_pid(int ac, char **av)
{
    struct sigaction act;
    int op = 0;

    init_signal_pid(act);
    if (ac == 2) {
        my_printf("my_pid: %d\nwaiting for enemy connection...\n", getpid());
        while (op != -1)
            op = pause();
        return 0;
    }
    if (ac == 3) {
        my_printf("my_pid: %d\n", getpid());
        if (kill(av_to_int(av[1]), SIGUSR1) == 0)
            my_printf("successfully connected\n\n");
        else
            return 84;
    } else
        return 84;
    return 0;
}

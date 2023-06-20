/*
** EPITECH PROJECT, 2022
** power rev
** File description:
** task04
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen (char const *str);

int is_num_alpha(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || c == ':')
        return (0);
    return (1);
}

char **my_word_to_array(char **av, char const *str)
{
    int i = 0;
    int j = 0;

    for (int k = 0; str[k]; k++) {
        if (is_num_alpha(str[k]) == 0) {
            av[i][j] = str[k];
            j++;
        }
        if (j != 0 && (is_num_alpha(str[k]) == 1 &&
            is_num_alpha(str[k + 1] == 0)) ) {
            av[i][j] = '\0';
            i++;
            j = 0;
        }
    }
    av[j + 1] = NULL;
    return (av);
}

/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** getnbr
*/

#include <stddef.h>
int my_strlen (char const *str);
int putinint(char const *str, int gnb, int i, int stock);

int putinint(char const *str, int gnb, int i, int stock)
{
    if (stock == 0)
        return -1;
    if (str[0] == '-') {
        stock /= -10;
        return stock;
    } else
        stock /= 10;
    return stock;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int testing = 0;
    int gnb = 0;
    int stock = 0;

    while (str[i] != '\0') {
        if ((str[i] == '\0') || ((str[i] < '0' || str[i] > '9') && (gnb > 0)))
            testing = 1;
        if (str[i] >= '0' && str[i] <= '9') {
            stock = stock + (str[i] - 48);
            gnb++;
            i++;
            stock *= 10;
        }
        if ((str[i] < '0' || str[i] > '9') && (gnb == 0))
            i++;
    }
    if (testing == 1)
        return -1;
    return putinint(str,gnb,i,stock);
}

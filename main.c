/*
** EPITECH PROJECT, 2022
** main myhunter
** File description:
** eh
*/

#include "include/mynavy.h"

int navy_h(void)
{
    char const *filepath = "navy_h";
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    stream = fopen(filepath, "r");
    if (stream == NULL)
        return -84;
    while ((nread = getline(&line, &len, stream)) != -1) {
        write(1, line, nread);
    }
    free(line);
    fclose(stream);
    return 0;
}

int checksize(size_navy snavy)
{
    if (snavy.navy_1 != 2)
        return -1;
    if (snavy.navy_2 != 3)
        return -1;
    if (snavy.navy_3 != 4)
        return -1;
    if (snavy.navy_4 != 5)
        return -1;
    return 0;
}

int checkfile(char *filepath)
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    int check = 0;
    ssize_t nread;
    size_navy snavy = {0, 0, 0, 0};
    stream = fopen(filepath, "r");
    if (stream == NULL)
        return 84;
    while ((nread = getline(&line, &len, stream)) != -1) {
        check++;
        snavy = checklinebyline(line, len, snavy);
    }
    free(line);
    fclose(stream);
    if (check != 4 || checksize(snavy) == -1)
        return 84;
    else
        return 0;
}

size_navy checklinebyline(char *buffer, size_t nb, size_navy snavy)
{
    int size = 0;
    int len = my_strlen(buffer);
    char **map = NULL;
    if (count_elem(buffer) != 2 || buffer[1] != ':')
        return snavy;
    size = buffer[0] - '0';
    buffer[len] = '\0';
    map = createmapfrombuffer(buffer, count_elem(buffer) + 1);
    if (check_pos(map) == 84 || check_sizeofnavy(map) == 84)
        return snavy;
    if (size == 2)
        snavy.navy_1 = size;
    if (size == 3)
        snavy.navy_2 = size;
    if (size == 4)
        snavy.navy_3 = size;
    if (size == 5)
        snavy.navy_4 = size;
    return snavy;
}

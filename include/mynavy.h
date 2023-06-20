/*
** EPITECH PROJECT, 2022
** header
** File description:
** navy
*/

#ifndef MYNAVY_H_
    #define MYNAVY_H_
    #define _GNU_SOURCE
    #include <stdlib.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdio.h>

typedef struct DCoordinates {
    int length;
    char firstSquare[3];
    char lastSquare[3];
} Coordinates;

typedef struct defonenavy {
    char letter;
    int number;
    int player;
    int pid_p1;
    pid_t pid_p2;
    int navy_p1;
    int navy_p2;
    int receivesignal;
} navy;

typedef struct defcoord {
    int x;
    int y;
} XY;

typedef struct checknavy {
    int navy_1;
    XY navy1;
    int navy_2;
    XY navy2;
    int navy_3;
    XY navy3;
    int navy_4;
    XY navy4;
} size_navy;

enum {
    A = 65,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
};

extern navy *varnavy;
int navy_p1(navy *varnavy, char my_map[8][8], char his_map[8][8]);
int navy_p2(navy *varnavy, char my_map[8][8], char his_map[8][8]);
int signal_connection(int signo, siginfo_t *pid1_oe, void *ptr);
void initsignal_forhm(struct sigaction act);
void initsignal(struct sigaction act);
int check_sizeofnavy(char **pos);
void kill_ftc(int pid, int SIG1, int SIG2);
int signal_from_attack(int signo, void *ptr);
navy *receive_attack(int pid, int player);
int hit_or_missed(int signo, void *ptr);
char **hitmissedftc_receive(char his_map[8][8], int player);
char **hitmissedftc_push(int pid, char my_map[8][8], int player);
void attack_navy(char *buf, int pid);
char **my_str_to_word_array(char const *str);
int my_strlen (char const *str);
int my_printf(const char *format, ...);
int check_pid(int ac, char **av);
int checkfile(char *filepath);
int count_largeur(char *buffer);
void waitsignal(int time);
int navy_h(void);
void *makepartofbuffer(char *map, char *buffer, int j);
char **createmapfrombuffer(char *buffer, ssize_t y);
char **put_in_map(char *buffer, ssize_t nb);
int count_elem(char *buffer);
size_navy checklinebyline(char *buffer, size_t nb, size_navy snavy);
int my_strcmp(char const *s1 , char const *s2);
int my_printf(const char *format, ...);
int av_to_int(char *av);
int check_pos(char **pos);
int checksize(size_navy snavy);
void read_file(FILE *file, char tab[8][8]);
void updatetab(char tab[8][8], Coordinates coordinates);
void update_x(char tab[8][8], Coordinates coordinates);
void update_y(char tab[8][8], Coordinates coordinates);
int get_lastx(char *lastSquare);
int get_lasty(char *lastSquare);
int get_firstx(char *firstSquare);
int get_firsty(char *firstSquare);
void parse_line(char *line, Coordinates *coordinates);
void init_tab(char tab[8][8]);
void init_map(char map[8][8]);
void void_map(char map[8][8]);
void print_tab(char tab[8][8]);
char (*map_ftcs(char *av))[8];
void remplirmap(char map[8][8], char map_ene[8][8], char *tab);

#endif

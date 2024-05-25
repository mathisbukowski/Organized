/*
** EPITECH PROJECT, 2023
** organized
** File description:
** shell_func.c
*/

#include <sys/types.h>
#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../include/my_printf.h"
#include "../include/my.h"
#include "../include/organized.h"
#include "../include/shell.h"

int sizeof_char(char **av)
{
    int i;

    for (i = 0; av[i] != NULL; i++);
    return i;
}

int add(void *data, char **args)
{
    int ac = sizeof_char(args);

    if (ac == 0 || ac % 2 != 0) {
        return 84;
    }
    for (int i = 0; i < ac; i += 2) {
        if (my_strcmp(args[i], "WIRE") == 0 ||
            my_strcmp(args[i], "ACTUATOR") == 0 ||
            my_strcmp(args[i], "SENSOR") == 0 ||
            my_strcmp(args[i], "PROCESSOR") == 0 ||
            my_strcmp(args[i], "DEVICE") == 0) {
            add_list(args[i + 1], args[i], data);
        } else {
            return 84;
        }
    }
    return 0;
}

int del(void *data, char **args)
{
    int ac = sizeof_char(args);
    int isDeleted = 0;

    if (ac == 0)
        return 84;
    for (int i = 0; i < ac; i++) {
        if (!my_str_isnum(args[i]))
            return 84;
        delete_list(data, my_atoi(args[i]), &isDeleted);
        if (!isDeleted)
            return 84;
    }
    return 0;
}

int sort(void *data, char **args)
{
    int reverse_detector = 0;
    int ac = sizeof_char(args);

    if (ac > 3 || ac == 0)
        return 84;
    for (int i = ac - 1; i >= 0; i--) {
        if (my_strcmp(args[i], "-r") == 0)
            reverse_detector = 1;
        if (my_strcmp(args[i], "NAME") == 0)
            sort_list(data, args[i], &reverse_detector);
        if (my_strcmp(args[i], "TYPE") == 0)
            sort_list(data, args[i], &reverse_detector);
        if (my_strcmp(args[i], "ID") == 0)
            sort_list(data, args[i], &reverse_detector);
    }
    return 0;
}

int disp(void *data, char **args)
{
    int ac = sizeof_char(args);

    if (ac != 0)
        return 84;
    display_list(data);
    return 0;
}

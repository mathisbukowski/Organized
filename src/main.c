/*
** EPITECH PROJECT, 2023
** bs-organized
** File description:
** main.c
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


int main(void)
{
    list_t *list = NULL;

    return workshop_shell(&list);
}

/*
** EPITECH PROJECT, 2023
** organized
** File description:
** display_list.c
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

static void print_info(const list_t *current)
{
    my_printf("%s ", current->data->type);
    my_printf("n°");
    my_put_nbr(current->data->id);
    my_printf(" - ");
    my_printf("\"%s\"\n", current->data->name);
}

void display_list(list_t **list)
{
    list_t *current = (*list);
    list_t *tmp = (*list);

    if (current == NULL)
        return;
    do {
        print_info(current);
        current = current->next;
    } while (current != NULL);
}

/*
** EPITECH PROJECT, 2023
** organized
** File description:
** add_list.c
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

static int get_max_id(list_t **list)
{
    list_t *current = (*list);
    int max_id = -1;

    if (current == NULL)
        return max_id;
    do {
        if (current->data->id > max_id) {
            max_id = current->data->id;
        }
        current = current->next;
    } while (current != NULL);
    return max_id;
}

static void add_list_bis(const char *name, const char *type, list_t *new_node)
{
    new_node->data = malloc(sizeof(addons_t));
    new_node->data->type = my_strdup(type);
    new_node->data->name = my_strdup(name);
}

static void print_info(list_t *new_node)
{
    my_printf("%s ", new_node->data->type);
    my_printf("n°");
    my_put_nbr(new_node->data->id);
    my_printf(" - ");
    my_printf("\"%s\" ", new_node->data->name);
    my_printf("added.\n");
}

void add_list(char *name, char *type, list_t **list)
{
    list_t *new_node = malloc(sizeof(list_t));
    int max_id = get_max_id(list);

    if (!new_node) {
        return;
    }
    add_list_bis(name, type, new_node);
    new_node->data->id = max_id + 1;
    print_info(new_node);
    new_node->next = (*list);
    (*list) = new_node;
}

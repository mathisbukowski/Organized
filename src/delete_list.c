/*
** EPITECH PROJECT, 2023
** organized
** File description:
** delete_list.c
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

static void print_info(const list_t *del_node)
{
    my_printf("%s ", del_node->data->type);
    my_printf("n°");
    my_put_nbr(del_node->data->id);
    my_printf(" - ");
    my_printf("\"%s\" ", del_node->data->name);
    my_printf("deleted.\n");
}

void null_list(list_t **list, int id_ref, list_t *to_remove, int *isDeleted)
{
    while (*list != NULL && (*list)->data->id == id_ref){
        to_remove = (*list);
        (*list) = (*list)->next;
        print_info(to_remove);
        *isDeleted = 1;
        free(to_remove);
    }
}

void delete_list(list_t **list, int id_ref, int *isDeleted)
{
    list_t *tmp;
    list_t *to_remove;

    *isDeleted = 0;
    null_list(list, id_ref, to_remove, isDeleted);
    tmp = (*list);
    while (tmp != NULL && tmp->next != NULL) {
        if (tmp->next->data->id == id_ref) {
            to_remove = tmp->next;
            tmp->next = tmp->next->next;
            print_info(to_remove);
            *isDeleted = 1;
            free(to_remove);
        } else {
            tmp = tmp->next;
        }
    }
}

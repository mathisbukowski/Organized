/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort_list.c
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

static list_t *last_node(list_t **head)
{
    list_t *tmp = (*head);

    while (tmp != NULL && tmp->next != NULL) {
        tmp = tmp->next;
    }
    return tmp;
}

static int compare_data(addons_t *a, addons_t *b, char const *model)
{
    if ((int)my_strcmp(model, "ID") == 0)
        return a->id - b->id;
    if ((int)my_strcmp(model, "NAME") == 0)
        return (int)my_strcmp(a->name, b->name);
    if ((int)my_strcmp(model, "TYPE") == 0)
        return (int)my_strcmp(a->type, b->type);
    else
        return a->id - b->id;
}

static list_t *partition(list_t *first, list_t *last, char const *model)
{
    list_t *pivot = first;
    list_t *front = first;
    addons_t *tmp;

    while (front != NULL && front != last){
        if (compare_data(front->data, last->data, model) < 0) {
            pivot = first;
            tmp = first->data;
            first->data = front->data;
            front->data = tmp;
            first = first->next;
        }
        front = front->next;
    }
    tmp = first->data;
    first->data = last->data;
    last->data = tmp;
    return pivot;
}

void quicksort(list_t *first, list_t *last, char const *model)
{
    list_t *pivot;

    if (first == last) {
        return;
    }
    pivot = partition(first, last, model);
    if (pivot != NULL && pivot->next != NULL) {
        quicksort(pivot->next, last, model);
    }
    if (pivot != NULL && first != pivot) {
        quicksort(first, pivot, model);
    }
}

void reverse_list(list_t **head)
{
    list_t *prev = NULL;
    list_t *current = (*head);
    list_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*head) = prev;
}

void sort_list(list_t **head, char const *model, int *reverse_index)
{
    if (*reverse_index == 1) {
        quicksort((*head), last_node(head), model);
        reverse_list(head);
    } else {
        quicksort((*head), last_node(head), model);
    }
}

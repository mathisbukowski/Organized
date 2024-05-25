/*
** EPITECH PROJECT, 2023
** bs-organized
** File description:
** organized.h
*/
typedef struct addons_s {
    char *type;
    char *name;
    int id;
} addons_t;

typedef struct list_s {
    addons_t *data;
    struct list_s *next;
} list_t;

#ifndef ORGANIZED_H
    #define ORGANIZED_H

void delete_list(list_t **list, int id_ref, int *isDeleted);
void add_list(char *name, char *type, list_t **list);
void display_list(list_t **list);
void sort_list(list_t **head, char const *model, int *reverse_index);
#endif //ORGANIZED_H

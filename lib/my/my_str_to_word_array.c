/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** string to word array
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

int isalphanum(char letter)
{
    if (letter >= 65 && letter <= 90) {
        return (1);
    }
    if (letter >= 97 && letter <= 122) {
        return (1);
    }
    if (letter >= 48 && letter <= 57) {
        return (1);
    }
    return (0);
}

int count_words_in_array(char *tab)
{
    int i;
    int count = 0;

    for (i = 0; tab[i] != '\0'; i++) {
        if (isalphanum(tab[i]) == 1 && isalphanum(tab[i + 1]) != 1) {
            count++;
        }
    }
    return (count);
}

int word_lenght(char *str, int i)
{
    int z = 0;

    while (isalphanum(str[i])) {
            z++;
            i++;
        }
    return (z);
}

char **my_str_to_word_array(char *str)
{
    int nb_word = count_words_in_array(str);
    char **result = malloc(sizeof(char *) * (nb_word + 1));
    int word_in_str = 0;
    int letter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalphanum(str[i]) == 1) {
            word_in_str = word_lenght(str, i);
            result[letter] = malloc(sizeof(char) * (word_in_str + 1));
            my_strncpy(result[letter], &str[i], word_in_str);
            letter++;
            i += word_in_str;
        }
    }
    result[nb_word] = 0;
    return (result);
}

/*
** EPITECH PROJECT, 2023
** my_printf.c
** File description:
** my_printf.c
*/

#include "../../include/my_printf.h"
#include <stdarg.h>
#include <unistd.h>

void display_scientist(int exponent_count)
{
    if (exponent_count >= 0) {
        write(1, "e+", 2);
        if (exponent_count < 10)
            write(1, "0", 1);
        my_put_nbr_f_flag((int)exponent_count);
    } else {
        write(1, "e-", 2);
        exponent_count *= (-1);
        if (exponent_count > -10)
            write(1, "0", 1);
        my_put_nbr_f_flag(exponent_count);
    }
}

void display_float(int sign, double nb)
{
    if (sign == -1)
        write(1, "-", 1);
    my_put_nbr_f_flag((int)nb);
    write(1, ".", 1);
    for (int i = 0; i < 6; i++) {
        nb = nb - (int)nb;
        nb *= 10;
        my_put_nbr_f_flag((int)nb);
    }
}

int e_flag(va_list arg)
{
    double nb = va_arg(arg, double);
    int exponent_count = 0;
    int sign = 1;

    if (nb < 0) {
        nb = -nb;
        sign = -1;
    }
    while (nb >= 10.0) {
        nb /= 10.0;
        exponent_count++;
    }
    while (nb < 1.0 && nb != 0.0) {
        nb *= 10.0;
        exponent_count--;
    }
    display_float(sign, nb);
    display_scientist(exponent_count);
    return 0;
}

/*
** MxLily
** My Hunter
** File description:
** puts.c
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}


int my_putstr(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb = nb + 1;
    }
    return (0);
}

int my_put_nbr(int nb)
{
    long long decimal = 1;

    while (nb / decimal / 10)
        decimal *=10;
    while (decimal) {
        my_putchar(nb /decimal +48);
        nb %= decimal;
        decimal /= 10;
    }
    return (0);
}

int my_nblen(int nb)
{
    int i = 0;

    if (nb == 0)
        return (1);
    while (nb != 0) {
        nb = nb / 10;
        i = i + 1;
    }
    return (i);
}

char *my_rtn_nbr(int nb)
{
    int len = my_nblen(nb);
    char *res = malloc(sizeof(char) * (len + 1));
    int i = 0;

    res[0] = '0';
    res[len] = '\0';
    while (len > 1) {
        res[i] = nb / ((len - 1) * 10) + 48;
        nb = nb % ((len - 1) * 10);
        i = i + 1;
        len = len - 1;
    }
    res[i] = nb + 48;
    return (res);
}

char *my_strcat(char *str1, char *str2)
{
    char *res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int i = 0;

    while (str1[i]) {
        res[i] = str1[i];
        i = i + 1;
    }
    for (int j = 0; str2[j]; j = j + 1) {
        res[i] = str2[j];
        i = i + 1;
    }
    res[i] = '\0';
    return (res);
}

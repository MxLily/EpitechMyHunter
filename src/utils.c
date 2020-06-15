/*
** MxLily
** My Hunter
** File description:
** utils.c
*/

#include "my.h"

int my_strlen(char *str)
{
    int nc = 0;

    while (str[nc] != '\0')
        nc = nc +1;
    return (nc);
}
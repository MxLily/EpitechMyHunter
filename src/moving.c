/*
** MxLily
** My Hunter
** File description:
** moving.c
*/

#include "my.h"
#include <stdio.h>
#include <time.h>

pokegame_t fly(pokegame_t pgt)
{
    srand(time(NULL));
    if (pgt.pos.x >= -40)
        pgt.pos.x -= rand()%11;
    if (pgt.pos.x < -40) {
        pgt.pos.y = rand()%1020/2  + rand()%1020/2;
        pgt.pos.x = 1920;
    }
    return (pgt);
}

pokegame_t shoot(pokegame_t pgt)
{
    pgt.mpos = sfMouse_getPosition((sfWindow *)pgt.wingame);
    if ((pgt.mpos.x >= pgt.pos.x - 100 && pgt.mpos.x <= pgt.pos.x + 100) &&
        (pgt.mpos.y >= pgt.pos.y - 100 && pgt.mpos.y <= pgt.pos.y + 100)) {
        pgt.pos.x = 1920;
        pgt.pos.y = rand()%1020;
        sfSprite_setPosition(pgt.spt_starly, pgt.pos);
        pgt.score++;
    } else
        pgt.life--;
    my_putstr("\nLife : ");
    my_put_nbr(pgt.life);
    my_putstr(", Score : ");
    my_put_nbr(pgt.score);
    my_putchar('\n');
    return (pgt);
}

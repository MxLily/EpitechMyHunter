/*
** MxLily
** My Hunter
** File description:
** main.c
*/

#include "my.h"
#include <stdio.h>
#include <time.h>

int main(int ac, char **av)
{
    pokegame_t pgt;

    if (ac != 1 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Welcome to Starly Hunt\n");
        my_putstr("Catch the most Starly as you can for win the party\n");
        my_putstr("Good luck and thanks for playing my game!\n");
        return(1);
    }

    pgt = create_game();
    srand(time(NULL));

    while (sfRenderWindow_isOpen(pgt.wingame)) {
        pgt = move(pgt);
        if (pgt.life == 0) {
            des_close(pgt);
            return (0);
        }
        while (sfRenderWindow_pollEvent(pgt.wingame, &pgt.event)) {
            pgt = evt_manag(pgt);
        }
    }
    des_close(pgt);
    return (0);
}

pokegame_t move(pokegame_t pgt)
{
    float seconds = pgt.timing.microseconds / 100000;
    char *score = my_rtn_nbr(pgt.score);
    char *score_total = my_strcat("Score : ", score);
    char *life = my_rtn_nbr(pgt.life);
    char *life_total = my_strcat("Life : ", life);
    sfText_setString(pgt.txt_life, life_total);
    sfText_setString(pgt.txt_score, score_total);

    sfRenderWindow_clear(pgt.wingame, sfBlack);
    sfRenderWindow_drawSprite(pgt.wingame, pgt.spt_back, NULL);
    sfRenderWindow_drawSprite(pgt.wingame, pgt.spt_starly, NULL);
    sfRenderWindow_drawText(pgt.wingame, pgt.txt_score, NULL);
    sfRenderWindow_drawText(pgt.wingame, pgt.txt_life, NULL);
    pgt.timing = sfClock_getElapsedTime(pgt.time);

    if (seconds > 0.5) {
        sfClock_restart(pgt.time);
        pgt.size.left = pgt.size.left + 125;
        if (pgt.size.left >= 500)
            pgt.size.left = 0;
        sfSprite_setTextureRect(pgt.spt_starly, pgt.size);
    }
    sfRenderWindow_display(pgt.wingame);
    pgt = fly(pgt);
    sfSprite_setPosition(pgt.spt_starly, pgt.pos);
    free(score);
    free(score_total);
    free(life);
    free(life_total);
    return (pgt);
}

pokegame_t evt_manag(pokegame_t pgt)
{

    if (pgt.event.type == sfEvtMouseButtonPressed)
        pgt = shoot(pgt);
    if (pgt.event.type == sfEvtClosed)
        sfRenderWindow_close(pgt.wingame);
    return (pgt);
}

pokegame_t create_game(void)
{
    pokegame_t pgt;
    srand(time(NULL));

    pgt.music = sfMusic_createFromFile("./rsrc/pokesong.ogg");
    sfMusic_play(pgt.music);
    pgt.size.top = 0;
    pgt.size.left = 0;
    pgt.size.height = 125;
    pgt.size.width = 125;
    pgt.mode = (sfVideoMode) {1920, 1080, 32};
    pgt.wingame = sfRenderWindow_create(pgt.mode, "Starly Hunt", sfClose, NULL);
    pgt.text_back = sfTexture_createFromFile("./rsrc/wp1.png", NULL);
    pgt.spt_back = sfSprite_create();
    sfSprite_setTexture(pgt.spt_back, pgt.text_back, sfTrue);
    pgt.text_starly = sfTexture_createFromFile("./rsrc/etourmifly.png", NULL);
    pgt.spt_starly = sfSprite_create();
    sfSprite_setTexture(pgt.spt_starly, pgt.text_starly, sfTrue);
    sfSprite_setTextureRect(pgt.spt_starly, pgt.size);
    sfRenderWindow_setFramerateLimit(pgt.wingame, 42);
    pgt.time = sfClock_create();
    pgt.pos.x = 1920;
    pgt.pos.y = rand()%800;
    pgt.life = 3;
    pgt.score = 0;
    sfSprite_setPosition(pgt.spt_starly, pgt.pos);
    my_putstr("Life : ");
    my_put_nbr(pgt.life);
    my_putstr(", Score : ");
    my_put_nbr(pgt.score);

    pgt.font = sfFont_createFromFile("./rsrc/solid.ttf");
    pgt.txt_score = sfText_create();
    pgt.txt_life = sfText_create();
    sfText_setPosition(pgt.txt_score, (sfVector2f){0, 100});
    sfText_setFont(pgt.txt_score, pgt.font);
    sfText_setFont(pgt.txt_life, pgt.font);
    sfText_setCharacterSize(pgt.txt_score, 50);
    sfText_setCharacterSize(pgt.txt_life, 50);
    return (pgt);
}

pokegame_t des_close(pokegame_t pgt)
{
    sfMusic_stop(pgt.music);
    sfTexture_destroy(pgt.text_back);
    sfTexture_destroy(pgt.text_starly);
    sfSprite_destroy(pgt.spt_back);
    sfSprite_destroy(pgt.spt_starly);
    sfMusic_destroy(pgt.music);
    sfRenderWindow_close(pgt.wingame);
    sfRenderWindow_destroy(pgt.wingame);
    sfSleep(sfSeconds(1));
    return (pgt);
}

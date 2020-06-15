/*
** EPITECH PROJECT, 2018
** Starly Hunt
** File description:
** my.h for MyHunter
*/

#ifndef MY_H_
#define MY_H_


/* include */

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* Struct */

struct pokegame_s
{
    sfVideoMode mode;
    sfMusic *music;
    sfEvent event;
    sfRenderWindow *wingame;
    sfSprite *spt_back;
    sfTexture *text_back;
    sfSprite *spt_starly;
    sfTexture *text_starly;
    sfClock *time;
    sfIntRect size;
    sfTime timing;
    sfVector2f pos;
    sfVector2i mpos;
    int score;
    int life;
    sfText *txt_score;
    sfText *txt_life;
    sfFont *font;

};

typedef struct pokegame_s pokegame_t;

/* main.c */

int main();
pokegame_t move(pokegame_t pgt);
pokegame_t evt_manag(pokegame_t pgt);
pokegame_t create_game(void);
pokegame_t des_close(pokegame_t pgt);
pokegame_t fly(pokegame_t pgt);
pokegame_t shoot(pokegame_t pgt);
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char *str);
char *my_strcat(char *str1, char *str2);
int my_nblen(int nb);
char *my_rtn_nbr(int nb);




#endif /* MY_H_ */

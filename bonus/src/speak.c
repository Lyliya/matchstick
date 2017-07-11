/*
** speak.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Tue Feb 14 14:52:21 2017 Guillaume Guerin
** Last update Tue Feb 14 20:19:34 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include "sfml.h"

void	hello(t_text *txt, sfVector2f txt_pos)
{
  sfText_setString(txt->text, HELLO);
  sfText_setFont(txt->text, txt->font);
  sfText_setCharacterSize(txt->text, 30);
  sfText_setColor(txt->text, sfBlack);
  sfText_setPosition(txt->text, txt_pos);
}

void	attack(t_text *txt, sfVector2f txt_pos, t_board *b)
{
  char	*st;

  st = my_strcat_str(ATTACK, get_nbr(b->ia_y));
  st = my_strcat_str(st, ATTACK2);
  st = my_strcat_str(st, get_nbr(b->ia_line));
  sfText_setString(txt->text, st);
  sfText_setFont(txt->text, txt->font);
  sfText_setCharacterSize(txt->text, 30);
  sfText_setColor(txt->text, sfBlack);
  sfText_setPosition(txt->text, txt_pos);
  free(st);
}

void		speak(t_graph *g, t_texture *t, t_board *b)
{
  t_text	txt;
  sfVector2f	txt_pos;

  txt_pos.x = 650;
  txt_pos.y = 80;
  txt.text = sfText_create();
  txt.font = sfFont_createFromFile("texture/portal.ttf");
  if (b->ia_line == 0 && b->ia_y == 0)
    hello(&txt, txt_pos);
  else
    attack(&txt, txt_pos, b);
  sfSprite_setPosition(t->speaksprite, t->speak_pos);
  sfRenderWindow_drawSprite(g->window, t->speaksprite, NULL);
  sfRenderWindow_drawText(g->window, txt.text, NULL);
  sfText_destroy(txt.text);
  sfFont_destroy(txt.font);
}

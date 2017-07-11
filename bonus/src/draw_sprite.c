/*
** draw_sprite.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Tue Feb 14 12:52:11 2017 Guillaume Guerin
** Last update Tue Feb 14 13:12:27 2017 Guillaume Guerin
*/

#include "sfml.h"

void	bg_glad(t_graph *g, t_texture *t)
{
  sfRenderWindow_clear(g->window, sfBlack);
  sfRenderWindow_drawSprite(g->window, t->bgsprite, NULL);
  sfSprite_setPosition(t->gladossprite, t->gla_pos);
  sfRenderWindow_drawSprite(g->window, t->gladossprite, NULL);
}

void	cake(t_graph *g, t_texture *t)
{
  sfSprite_setPosition(t->cakesprite, t->scale);
  sfSprite_setScale(t->cakesprite, t->pos);
  sfRenderWindow_drawSprite(g->window, t->cakesprite, NULL);
}

void	cakeoff(t_graph *g, t_texture *t)
{
  sfSprite_setPosition(t->cakeoffsprite, t->scale);
  sfSprite_setScale(t->cakeoffsprite, t->pos);
  sfRenderWindow_drawSprite(g->window, t->cakeoffsprite, NULL);
}

void		pince(t_graph *g, t_texture *t)
{
  sfVector2f	pos;

  pos = t->hand_pos;
  pos.y -= 30;
  pos.x += 11;
  sfSprite_setPosition(t->pincesprite, t->hand_pos);
  sfSprite_setScale(t->pincesprite, t->hand_scale);
  sfSprite_setScale(t->brassprite, t->hand_scale);
  sfRenderWindow_drawSprite(g->window, t->pincesprite, NULL);
  while (pos.y >= -20)
    {
      sfSprite_setPosition(t->brassprite, pos);
      pos.y -= 30;
      sfRenderWindow_drawSprite(g->window, t->brassprite, NULL);
    }
}

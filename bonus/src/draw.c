/*
** draw.c for  in /home/lyliya/raytracer
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Fri Feb 10 11:47:04 2017 Guillaume Guerin
** Last update Tue Feb 14 18:37:01 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "sfml.h"

void		draw_line(t_graph *g, t_texture *t, t_text *tt, int line)
{
  char	*txt;
  sfVector2f position;

  position.x = 190;
  position.y = 367;
  txt = get_nbr(line);
  sfText_setString(tt->text, txt);
  sfText_setFont(tt->text, tt->font);
  sfText_setCharacterSize(tt->text, 50);
  sfText_setColor(tt->text, sfBlack);
  sfText_setPosition(tt->text, position);
  sfRenderWindow_clear(g->window, sfBlack);
  sfRenderWindow_drawSprite(g->window, t->linesprite, NULL);
  sfRenderWindow_drawText(g->window, tt->text, NULL);
  sfRenderWindow_display(g->window);
  free(txt);
}

int		choose_line(t_graph *g, t_texture *t)
{
  t_text	txt;
  int		line;

  line = 1;
  txt.text = sfText_create();
  txt.font = sfFont_createFromFile("texture/portal.ttf");
  line_menu(g, t, &line, &txt);
  return (m_game(g, t, line));
}

void	draw_menu(t_graph *g, int state, t_texture *t)
{
  sfRenderWindow_clear(g->window, sfBlack);
  if (state == 0)
    sfRenderWindow_drawSprite(g->window, t->playmenu, NULL);
  else if (state == 1)
    sfRenderWindow_drawSprite(g->window, t->rulesmenu, NULL);
  else
    sfRenderWindow_drawSprite(g->window, t->rulesopen, NULL);
  sfRenderWindow_display(g->window);
}

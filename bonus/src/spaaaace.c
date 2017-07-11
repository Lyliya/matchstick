/*
** spaaaace.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Tue Feb 14 17:22:33 2017 Guillaume Guerin
** Last update Mon Feb 27 14:40:23 2017 Guillaume Guerin
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "sfml.h"

void	draw_space(t_graph *g, t_texture *t, sfVector2f dir)
{
  sfRenderWindow_clear(g->window, sfBlack);
  sfRenderWindow_drawSprite(g->window, t->spacesprite, NULL);
  sfSprite_move(t->wheatleysprite, dir);
  sfRenderWindow_drawSprite(g->window, t->wheatleysprite, NULL);
  sfRenderWindow_display(g->window);
}

void	spaaaace(t_graph *g, t_texture *t)
{
  int		bool;
  sfVector2f	wheatley_pos;
  sfVector2f	dir;
  t_sound	sound;

  bool = 0;
  wheatley_pos.x = 0;
  wheatley_pos.y = 200;
  dir.x = 0.25;
  dir.y = -0.001;
  sound.music = sfMusic_createFromFile("texture/space.ogg");
  sound.music2 = sfMusic_createFromFile("texture/space2.ogg");
  sfMusic_play(sound.music);
  sfRenderWindow_clear(g->window, sfBlack);
  sfSprite_setPosition(t->wheatleysprite, wheatley_pos);
  while (sfSprite_getPosition(t->wheatleysprite).x <= 1280)
    {
      if (sfMusic_getStatus(sound.music) != sfPlaying && bool == 0)
	{
	  sfMusic_play(sound.music2);
	  bool = 1;
	}
      draw_space(g, t, dir);
      dir.y += 0.00001;
    }
}

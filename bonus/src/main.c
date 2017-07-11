/*
** main.c for  in /home/lyliya/raytracer
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Fri Feb 10 11:42:26 2017 Guillaume Guerin
** Last update Tue Feb 14 21:20:40 2017 Guillaume Guerin
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "sfml.h"

int	menu(t_graph *graph, t_texture *t)
{
  int	i;

  i = 0;
  while (sfKeyboard_isKeyPressed(sfKeyReturn) == sfFalse)
    {
      if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
	i = 0;
      if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
	i = 1;
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	return (0);
      draw_menu(graph, i, t);
    }
  if (i == 1)
    {
      while (sfKeyboard_isKeyPressed(sfKeyBack) == sfFalse)
	draw_menu(graph, 3, t);
      menu(graph, t);
    }
  if (i == 0)
    return (choose_line(graph, t));
  return (0);
}

void	init(t_texture *t)
{
  t->playtexture = sfTexture_createFromFile("texture/menuplay.png", NULL);
  t->playmenu = sfSprite_create();
  sfSprite_setTexture(t->playmenu, t->playtexture, 0);
  t->rulestexture = sfTexture_createFromFile("texture/menurules.png", NULL);
  t->rulesmenu = sfSprite_create();
  sfSprite_setTexture(t->rulesmenu, t->rulestexture, 0);
  t->opentexture = sfTexture_createFromFile("texture/rules.png", NULL);
  t->rulesopen = sfSprite_create();
  sfSprite_setTexture(t->rulesopen, t->opentexture, 0);
  t->linetexture = sfTexture_createFromFile("texture/choosenbline.png", NULL);
  t->linesprite = sfSprite_create();
  sfSprite_setTexture(t->linesprite, t->linetexture, 0);
  t->bgtexture = sfTexture_createFromFile("texture/portal.png", NULL);
  t->bgsprite = sfSprite_create();
  sfSprite_setTexture(t->bgsprite, t->bgtexture, 0);
  t->caketexture = sfTexture_createFromFile("texture/caketexture.png", NULL);
  t->cakesprite = sfSprite_create();
  sfSprite_setTexture(t->cakesprite, t->caketexture, 0);
  t->cakeofftexture =sfTexture_createFromFile("texture/cakeofftexture.png",
					      NULL);
  t->cakeoffsprite = sfSprite_create();
  sfSprite_setTexture(t->cakeoffsprite, t->cakeofftexture, 0);
  rinit(t);
}

void	rrinit(t_texture *t)
{
  t->wheatleytexture = sfTexture_createFromFile("texture/wheatley.png", NULL);
  t->wheatleysprite = sfSprite_create();
  sfSprite_setTexture(t->wheatleysprite, t->wheatleytexture, 0);
  t->spacetexture = sfTexture_createFromFile("texture/space.png", NULL);
  t->spacesprite = sfSprite_create();
  sfSprite_setTexture(t->spacesprite, t->spacetexture, 0);
}

void	rinit(t_texture *t)
{
  t->gladostexture = sfTexture_createFromFile("texture/glados.png", NULL);
  t->gladossprite = sfSprite_create();
  sfSprite_setTexture(t->gladossprite, t->gladostexture, 0);
  t->pincetexture = sfTexture_createFromFile("texture/pince.png", NULL);
  t->pincesprite = sfSprite_create();
  sfSprite_setTexture(t->pincesprite, t->pincetexture, 0);
  t->brastexture = sfTexture_createFromFile("texture/bras.png", NULL);
  t->brassprite = sfSprite_create();
  sfSprite_setTexture(t->brassprite, t->brastexture, 0);
  t->speaktexture = sfTexture_createFromFile("texture/speak.png", NULL);
  t->speaksprite = sfSprite_create();
  sfSprite_setTexture(t->speaksprite, t->speaktexture, 0);
  t->pos.x = 0.18;
  t->pos.y = 0.18;
  t->hand_pos.y = 30;
  t->hand_scale.x = 0.25;
  t->hand_scale.y = 0.25;
  t->gla_pos.x = 850;
  t->gla_pos.y = 0;
  t->speak_pos.x = 590;
  t->speak_pos.y = 20;
  t->speak_scale.x = 1;
  t->speak_scale.y = 1;
  rrinit(t);
}

int			main(int argc, char **argv)
{
  t_graph		graph;
  t_texture		t;
  int			ret;

  (void)(argc);
  (void)(argv);
  init(&t);
  srand(getpid());
  graph.window = open_window(1280, 720);
  graph.sprite = sfSprite_create();
  graph.texture = sfTexture_create(1280, 720);
  ret = menu(&graph, &t);
  if (ret != 0)
    spaaaace(&graph, &t);
  return (ret);
}

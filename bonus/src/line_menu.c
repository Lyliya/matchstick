/*
** line_menu.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 22:07:29 2017 Guillaume Guerin
** Last update Tue Feb 14 14:43:46 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include "sfml.h"

int	line_menu(t_graph *g, t_texture *t, int *line, t_text *txt)
{
  int	bool;

  bool = 0;
  while (sfKeyboard_isKeyPressed(sfKeySpace) == sfFalse)
    {
      if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && *line > 1
	  && bool == 0)
	{
	  *line -= 1;
	  bool = 1;
	}
      if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && *line < 5 &&
	  bool == 0)
	{
	  *line += 1;
	  bool = 1;
	}
      if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfFalse &&
	  sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse)
	bool = 0;
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	return (666);
      draw_line(g, t, txt, *line);
    }
  return (0);
}

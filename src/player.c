/*
** player.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 15:13:00 2017 Guillaume Guerin
** Last update Wed Feb 22 17:34:44 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include "my.h"

char	**player(t_board *b, int line, int *pl_nb)
{
  int	game_line;
  int	ret;

  ret = 1;
  aff_board(b->board);
  my_putstr("\nYour turn:\n");
  while (ret != 0)
    {
      ret = aff_line(&game_line, pl_nb, line, b);
      if (ret == 84)
	{
	  free_board(b->board);
	  return (NULL);
	}
    }
  b->board = update_board(game_line, *pl_nb, b->board);
  aff_board(b->board);
  return (b->board);
}

/*
** change_board.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Tue Feb 14 09:30:57 2017 Guillaume Guerin
** Last update Tue Feb 14 13:19:36 2017 Guillaume Guerin
*/

#include "sfml.h"

void	change_board(t_board *b)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (b->board[i] != '\0')
    {
      j = 0;
      while (b->board[i][j] != '\0')
	{
	  if (b->board[i][j] == 'o')
	    b->board[i][j] = 'x';
	  j += 1;
	}
      i += 1;
    }
}

int	check_win(t_board *b, int ret)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (b->board[i] != '\0')
    {
      j = 0;
      while (b->board[i][j] != '\0')
	{
	  if (b->board[i][j] == '|')
	    return (0);
	  j += 1;
	}
      i += 1;
    }
  return (ret);
}

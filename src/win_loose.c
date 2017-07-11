/*
** win_loose.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 13:39:28 2017 Guillaume Guerin
** Last update Tue Feb 14 16:49:10 2017 Guillaume Guerin
*/

#include "my.h"

void	win(char **board)
{
  aff_board(board);
  my_putstr("I lost... snif... but I'll get you next time!!\n");
}

void	loose(void)
{
  my_putstr("You lost, too bad...\n");
}

int	win_loose(char **board)
{
  int	i;
  int	j;

  i = 1;
  while (board[i] != '\0')
    {
      j = 0;
      while (board[i][j] != '\0')
	{
	  if (board[i][j] == '|')
	    return (0);
	  j += 1;
	}
      i += 1;
    }
  return (1);
}

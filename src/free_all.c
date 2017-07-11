/*
** free_all.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 15:17:26 2017 Guillaume Guerin
** Last update Wed Feb 22 13:34:58 2017 Guillaume Guerin
*/

#include <stdlib.h>

void	free_board(char **board)
{
  int	i;

  i = 0;
  while (board[i] != '\0')
    {
      free(board[i]);
      i += 1;
    }
  free(board);
}

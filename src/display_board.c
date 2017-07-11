/*
** display_board.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 11:54:00 2017 Guillaume Guerin
** Last update Tue Feb 14 16:49:50 2017 Guillaume Guerin
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	aff_board(char **board)
{
  int	i;

  i = 0;
  while (board[i] != '\0')
    {
      my_putstr(board[i]);
      my_putstr("\n");
      i += 1;
    }
}

char	*first_line(char *board, int max)
{
  int	j;

  j = 0;
  if ((board = malloc(sizeof(char) * (max + 1))) == NULL)
    return (NULL);
  while (j < max)
    board[j++] = '*';
  board[j] = '\0';
  return (board);
}

char	*line_func(char *board, int max, int stick)
{
  int	j;
  int	sp;
  int	st;

  j = 0;
  st = 0;
  sp = 0;
  if ((board = malloc(sizeof(char) * (max + 1))) == NULL)
    return (NULL);
  board[j++] = '*';
  while (sp++ < ((max - stick) / 2) - 1)
    board[j++] = ' ';
  while (st++ < stick)
    board[j++] = '|';
  sp = 0;
  while (sp++ < ((max - stick) / 2) - 1)
    board[j++] = ' ';
  board[j++] = '*';
  board[j] = '\0';
  return (board);
}

char	**create_board(int line)
{
  int	i;
  int	stick;
  int	max;
  char	**board;

  i = 0;
  stick = 1;
  max = (line * 2) + 1;
  if ((board = malloc(sizeof(char *) * (line + 3))) == NULL)
    return (NULL);
  if ((board[i] = first_line(board[i], max)) == NULL)
    return (NULL);
  i += 1;
  while (line > 0)
    {
      if ((board[i] = line_func(board[i], max, stick)) == NULL)
	return (NULL);
      i += 1;
      stick += 2;
      line -= 1;
    }
  if ((board[i] = first_line(board[i], max)) == NULL)
    return (NULL);
  board[++i] = '\0';
  return (board);
}

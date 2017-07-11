/*
** ai_game.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Tue Feb 14 13:21:35 2017 Guillaume Guerin
** Last update Tue Feb 14 21:21:19 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include <unistd.h>
#include "sfml.h"

int     check_stick(char **board, int line)
{
  int   i;

  i = 0;
  while (board[line][i] != '\0')
    {
      if (board[line][i] == '|')
	return (0);
      i += 1;
    }
  return (1);
}

int     check_nb(char **board, int line, int nb)
{
  int   i;
  int   stick;

  i = 0;
  stick = 0;
  while (board[line][i] != '\0')
    {
      if (board[line][i] == '|')
	stick += 1;
      i += 1;
    }
  if (stick >= nb)
    return (0);
  return (1);
}

void	get_attack(int *line, int *nb, t_board *b)
{
  *line = (rand() % b->line) + 1;
  while (check_stick(b->board, *line) == 1)
    *line = (rand() % b->line) + 1;
  *nb = (rand() % ((b->line * 2) - 1)) + 1;
  while (check_nb(b->board, *line, *nb) == 1)
    *nb = (rand() % ((b->line * 2) - 1)) + 1;
}

void	new_board(int line, int nb, t_board *b)
{
  int	i;

  i = my_strlen(b->board[line]);
  while (b->board[line][i] != '|')
    i -= 1;
  while (nb > 0)
    {
      if (b->board[line][i] == '|')
	{
	  b->board[line][i] = 'x';
	  nb -= 1;
	}
      i -= 1;
    }
}

int	ai_game(t_board *b)
{
  get_attack(&b->ia_line, &b->ia_y, b);
  new_board(b->ia_line, b->ia_y, b);
  return (check_win(b, 1));
}

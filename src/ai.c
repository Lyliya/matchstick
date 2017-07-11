/*
** ai.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 13:54:54 2017 Guillaume Guerin
** Last update Thu Feb 23 08:51:09 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include "my.h"

int	check_stick(char **board, int line)
{
  int	i;

  i = 0;
  while (board[line][i] != '\0')
    {
      if (board[line][i] == '|')
	return (0);
      i += 1;
    }
  return (1);
}

int	check_nb(char **board, int line, int nb)
{
  int	i;
  int	stick;

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

int	grundy(t_board *b)
{
  int	i;
  int	j;
  int	stick;
  int	gr;

  i = 0;
  stick = 0;
  gr = 0;
  while (b->board[i] != '\0')
    {
      j = 0;
      stick = 0;
      while (b->board[i][j] != '\0')
	{
	  if (b->board[i][j] == '|')
	    stick += 1;
	  j += 1;
	}
      gr = gr ^ stick;
      i += 1;
    }
  return (gr);
}

char		**ai_f(t_board *b, __attribute__ ((unused)) int line)
{
  t_ai		save;
  t_aimm	min_max;
  int		final;

  min_max.x = 1;
  min_max.ga_line = first_playable(b);
  final = 0;
  save.gr = 999;
  save.save_line = min_max.ga_line;
  save.save_x = 1;
  if (nb_st(b) <= b->max_st)
    final = 1;
  while (playable(b, min_max.ga_line) != 0)
    {
      main_ai(b, &save, &min_max, final);
      reset(b);
      min_max.x = 1;
      min_max.ga_line += 1;
    }
  my_putstr("\nAI removed ");
  my_putnbr(save.save_x);
  my_putstr(" match(es) from line ");
  my_putnbr(save.save_line);
  my_putstr("\n");
  return (update_board(save.save_line, save.save_x, b->board));
}

char	**ai(t_board *b, int line)
{
  int	game_line;
  int	nb;

  game_line = (rand() % line) + 1;
  while (check_stick(b->board, game_line) == 1)
    game_line = (rand() % line) + 1;
  nb = (rand() % b->max_st) + 1;
  while (check_nb(b->board, game_line, nb) == 1)
    nb = (rand() % b->max_st) + 1;
  my_putstr("\nAI removed ");
  my_putnbr(nb);
  my_putstr(" match(es) from line ");
  my_putnbr(game_line);
  my_putstr("\n");
  b->board = update_board(game_line, nb, b->board);
  return (b->board);
}

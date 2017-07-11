/*
** main.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 12:54:24 2017 Guillaume Guerin
** Last update Thu Feb 23 20:13:34 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	check_match(t_board *b, int game_line, int nb)
{
  int	i;
  int	stick;

  i = 0;
  stick = 0;
  if (nb <= 0 || nb > b->max_st)
    {
      nb_err(nb, b->max_st);
      return (1);
    }
  while (b->board[game_line][i] != '\0')
    {
      if (b->board[game_line][i] == '|')
	stick += 1;
      i += 1;
    }
  if (stick < nb)
    {
      my_putstr(ENOUGH);
      return (1);
    }
  return (0);
}

int	aff_line(int *game_line, int *nb, int line, t_board *b)
{
  char	*gnl;

  my_putstr("Line: ");
  if ((gnl = get_next_line(0)) == NULL)
    return (84);
  *game_line = my_getnbr(gnl);
  if (*game_line > line || *game_line <= 0)
    {
      line_err(*game_line, line);
      return (1);
    }
  free(gnl);
  my_putstr("Matches: ");
  if ((gnl = get_next_line(0)) == NULL)
    return (84);
  *nb = my_getnbr(gnl);
  if (check_match(b, *game_line, *nb) == 1)
    return (1);
  my_putstr("Player removed ");
  my_putnbr(*nb);
  my_putstr(" match(es) from line ");
  my_putnbr(*game_line);
  my_putstr("\n");
  free(gnl);
  return (0);
}

char	**update_board(int game_line, int nb, char **board)
{
  int	i;

  i = my_strlen(board[game_line]);
  while (board[game_line][i] != '|')
    i -= 1;
  while (nb > 0)
    {
      board[game_line][i] = ' ';
      i -= 1;
      nb -= 1;
    }
  return (board);
}

int	game(t_board *b, int line)
{
  int	bool;
  int	pl_nb;

  bool = 0;
  pl_nb = 0;
  while (bool == 0)
    {
      if ((b->board = player(b, line, &pl_nb)) == NULL)
	return (0);
      bool = win_loose(b->board);
      if (bool == 0)
	{
	  my_putstr("\nAI's turn...");
	  if ((b->board = ai_f(b, line)) == NULL)
	    return (84);
	}
      else
	{
	  loose(b->board);
	  return (2);
	}
      bool = win_loose(b->board);
    }
  win(b->board);
  return (1);
}

int		main(int ac, char **av)
{
  int		ret;
  int		line;
  t_board	b;

  if (ac != 3)
    return (84);
  line = my_getnbr(av[1]);
  if (line < 1 || line > 100)
    {
      my_putstr(INV);
      return (84);
    }
  b.max_st = my_getnbr(av[2]);
  if (b.max_st <= 0)
    return (84);
  if ((b.board = create_board(line)) == NULL)
    return (84);
  srand(getpid());
  ret = game(&b, line);
  if (ret != 0)
    free_board(b.board);
  if (ret == 84)
    return (84);
  return (ret);
}

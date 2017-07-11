/*
** m_game.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 22:18:33 2017 Guillaume Guerin
** Last update Tue Feb 14 21:22:53 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include "sfml.h"

int		get_first_stick(int *i, int *j, char **board)
{
  *i = 0;
  *j = 0;
  while (board[*i] != '\0')
    {
      *j = 0;
      while (board[*i][*j] != '\0')
	{
	  if (board[*i][*j] == '|')
	    return (0);
	  *j += 1;
	}
      *i += 1;
    }
  return (0);
}

int	selection(t_graph *g, t_texture *t, t_board *b)
{
  int	bool;

  bool = 0;
  while (sfKeyboard_isKeyPressed(sfKeySpace) == sfFalse)
    {
      if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && bool == 0)
	bool = keyReturn(b);
      if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && bool == 0 &&
	  (b->board[b->c_line][b->c_y - 1] == '|' ||
	   b->board[b->c_line][b->c_y - 1] == 'x' ||
	   b->board[b->c_line][b->c_y - 1] == 'o'))
	bool = keyLeft(t, b);
      if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && bool == 0 &&
	  (b->board[b->c_line][b->c_y + 1] == '|' ||
	   b->board[b->c_line][b->c_y + 1] == 'x' ||
	   b->board[b->c_line][b->c_y + 1] == 'o'))
	bool = keyRight(t, b);
      if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfFalse &&
	  sfKeyboard_isKeyPressed(sfKeyLeft) == sfFalse &&
	  sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse)
	bool = 0;
      draw_game(g, t, b);
    }
  change_board(b);
  return (check_win(b, 2));
}

void		draw_game(t_graph *g, t_texture *t, t_board *b)
{
  int		i;
  int		j;

  i = -1;
  t->scale.x = 50;
  t->scale.y = 30;
  bg_glad(g, t);
  while (b->board[++i] != '\0')
    {
      j = 0;
      while (b->board[i][j] != '\0')
	{
	  if (b->board[i][j] == '|')
	    cake(g, t);
	  if (b->board[i][j] == 'o' || b->board[i][j] == 'x')
	    cakeoff(g, t);
	  t->scale.x += 75;
	  j += 1;
	}
      t->scale.x = 30;
      t->scale.y += 100;
    }
  speak(g, t, b);
  pince(g, t);
  sfRenderWindow_display(g->window);
}

int	game(t_graph *g, t_texture *t, t_board *b, int bool)
{
  int	ret;

  ret = 0;
  while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfFalse)
    {
      if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue && bool == 0)
	bool = keyLeft(t, b);
      if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue && bool == 0)
	bool = keyRight(t, b);
      if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && bool == 0)
	bool = keyUp(t, b);
      if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue && bool == 0)
	bool = keyDown(t, b);
      if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && bool == 0 &&
	  b->board[b->c_line][b->c_y] == '|')
	{
	  if ((ret = selection(g, t, b)) != 0)
	    return (ret);
	  if ((ret = ai_game(b)) != 0)
	    return (ret);
	}
      bool = status();
      draw_game(g, t, b);
    }
  return (0);
}

int		m_game(t_graph *g, t_texture *t, int line)
{
  t_board	b;
  int		bool;

  b.line = line;
  bool = 0;
  t->hand_pos.x = 35 + ((((b.line * 2) + 1) / 2) * 75);
  b.board = create_board(line);
  b.ia_line = 0;
  b.ia_y = 0;
  get_first_stick(&b.c_line, &b.c_y, b.board);
  return (game(g, t, &b, bool));
}

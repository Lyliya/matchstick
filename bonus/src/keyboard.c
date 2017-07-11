/*
** keyboard.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Tue Feb 14 09:58:41 2017 Guillaume Guerin
** Last update Tue Feb 14 21:06:50 2017 Guillaume Guerin
*/

#include "sfml.h"

int	keyRight(t_texture *t, t_board *b)
{
  if (b->board[b->c_line][b->c_y + 1] == '|' ||
      b->board[b->c_line][b->c_y + 1] == 'x' ||
      b->board[b->c_line][b->c_y + 1] == 'o')
    {
      t->hand_pos.x += 75;
      b->c_y += 1;
      return (1);
    }
  return (0);
}

int	keyLeft(t_texture *t, t_board *b)
{
  if (b->board[b->c_line][b->c_y - 1] == '|' ||
      b->board[b->c_line][b->c_y - 1] == 'x' ||
      b->board[b->c_line][b->c_y - 1] == 'o')
    {
      t->hand_pos.x -= 75;
      b->c_y -= 1;
      return (1);
    }
  return (0);
}

int	keyUp(t_texture *t, t_board *b)
{
  if (b->board[b->c_line - 1][b->c_y] == '|' ||
      b->board[b->c_line - 1][b->c_y] == 'x' ||
      b->board[b->c_line - 1][b->c_y] == 'o')
    {
      t->hand_pos.y -= 100;
      b->c_line -= 1;
      return (1);
    }
  return (0);
}

int	keyDown(t_texture *t, t_board *b)
{
  if (b->board[b->c_line + 1][b->c_y] == '|' ||
      b->board[b->c_line + 1][b->c_y] == 'x' ||
      b->board[b->c_line + 1][b->c_y] == 'o')
    {
      t->hand_pos.y += 100;
      b->c_line += 1;
      return (1);
    }
  return (0);
}

int	keyReturn(t_board *b)
{
  if (b->board[b->c_line][b->c_y] == '|')
    b->board[b->c_line][b->c_y] = 'o';
  else if (b->board[b->c_line][b->c_y] == 'o')
    b->board[b->c_line][b->c_y] = '|';
  return (1);
}

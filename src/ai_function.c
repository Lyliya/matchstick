/*
** ai_function.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/src
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Thu Feb 23 08:25:21 2017 Guillaume Guerin
** Last update Thu Feb 23 08:42:10 2017 Guillaume Guerin
*/

#include "my.h"

int     nb_st(t_board *b)
{
  int   i;
  int   j;
  int   stick;

  i = 0;
  stick = 0;
  while (b->board[i] != '\0')
    {
      j = 0;
      while (b->board[i][j] != '\0')
	{
	  if (b->board[i][j] == '|')
	    stick += 1;
	  j += 1;
	}
      i += 1;
    }
  return (stick);
}

void    reset(t_board *b)
{
  int   i;
  int   j;

  i = 0;
  while (b->board[i] != '\0')
    {
      j = 0;
      while (b->board[i][j] != '\0')
	{
	  if (b->board[i][j] == 'o')
	    b->board[i][j] = '|';
	  j += 1;
	}
      i += 1;
    }
}

int     playable(t_board *b, int l)
{
  int   i;
  int   line;
  int   j;
  int   bool;

  j = 0;
  i = l;
  line = 0;
  bool = 0;
  while (b->board[i] != '\0')
    {
      j = 0;
      while (b->board[i][j] != '\0')
	{
	  if (b->board[i][j] == '|' && bool == 0)
	    {
	      line += 1;
	      bool = 1;
	    }
	  j += 1;
	}
      i += 1;
      bool = 0;
    }
  return (line);
}

int     first_playable(t_board *b)
{
  int   i;
  int   j;

  i = 0;
  while (b->board[i] != '\0')
    {
      j = 0;
      while (b->board[i][j] != '\0')
	{
	  if (b->board[i][j] == '|')
	    return (i);
	  j += 1;
	}
      i += 1;
    }
  return (0);
}

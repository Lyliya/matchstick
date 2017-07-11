/*
** ai_form.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Thu Feb 23 08:29:45 2017 Guillaume Guerin
** Last update Sun Feb 26 13:46:58 2017 Guillaume Guerin
*/

#include "my.h"

void	ai_form(t_ai *save, t_aimm *min_max, int form)
{
  if (form == 1 && save->gr != 0)
    {
      save->save = save->gr;
      save->save_line = min_max->ga_line;
      save->save_x = min_max->x;
    }
  else if (form == 0)
    {
      save->save = save->gr;
      save->save_line = min_max->ga_line;
      save->save_x = min_max->x;
    }
}

void	main_ai(t_board *b, t_ai *save, t_aimm *min_max, int final)
{
  int	i;

  i = 0;
  save->save = 999;
  while (b->board[min_max->ga_line][i + 1] != '\0')
    {
      if (b->board[min_max->ga_line][i] == '|' && min_max->x <= b->max_st)
	{
	  b->board[min_max->ga_line][i] = 'o';
	  save->gr = grundy(b);
	  if (save->gr < save->save)
	    ai_form(save, min_max, final);
	  min_max->x += 1;
	}
      i += 1;
    }
}

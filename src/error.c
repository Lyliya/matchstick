/*
** error.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Tue Feb 14 16:18:21 2017 Guillaume Guerin
** Last update Wed Feb 22 17:30:46 2017 Guillaume Guerin
*/

#include <unistd.h>
#include "my.h"

void	nb_err(int nb, int max)
{
  if (nb == 0)
    my_putstr(LEAST);
  else if (nb < 0)
    my_putstr(POS);
  if (nb > max)
    {
      my_putstr(MORE);
      my_putnbr(max);
      my_putstr(MORE2);
    }
}

void	line_err(int nb, int line)
{
  if (nb > line || nb == 0)
    my_putstr(RANGE);
  if (nb == -666)
    write(1, "\n", 1);
  if (nb < 0)
    my_putstr(POS);
}

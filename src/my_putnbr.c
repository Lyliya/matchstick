/*
** my_putnbr.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 14:58:14 2017 Guillaume Guerin
** Last update Thu Feb 16 09:03:50 2017 Guillaume Guerin
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putnbr(int nb)
{
  unsigned int n;

  n = nb;
  if (nb < 0)
    {
      my_putstr("-");
      n = -nb;
    }
  if (n > 9)
    my_putnbr(n / 10);
  my_putchar((n % 10) + 48);
}

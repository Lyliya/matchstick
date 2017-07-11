/*
** my_strlen.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Tue Feb 14 13:29:41 2017 Guillaume Guerin
** Last update Tue Feb 14 13:30:12 2017 Guillaume Guerin
*/

#include "sfml.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

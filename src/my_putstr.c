/*
** my_putstr.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 12:53:06 2017 Guillaume Guerin
** Last update Mon Feb 13 12:56:50 2017 Guillaume Guerin
*/

#include <unistd.h>
#include <stdlib.h>

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (84);
  while (str[i] != '\0')
    write(1, &str[i++], 1);
  return (0);
}

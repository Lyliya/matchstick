/*
** get_nbr.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 20:48:27 2017 Guillaume Guerin
** Last update Mon Feb 13 21:20:58 2017 Guillaume Guerin
*/

#include <stdlib.h>

char	*get_nbr(int nb)
{
  int	j;
  int	save;
  int	mult;
  char	*nbr;

  j = 0;
  save = nb;
  mult = 1;
  while (save > 0)
    {
      save /= 10;
      j += 1;
      mult *= 10;
    }
  if ((nbr = malloc(sizeof(char) * (j + 1))) == NULL)
    return (NULL);
  mult /= 10;
  j = 0;
  while (mult > 0)
    {
      nbr[j++] = (nb / mult) % 10 + 48;
      mult /= 10;
    }
  nbr[j] = '\0';
  return (nbr);
}

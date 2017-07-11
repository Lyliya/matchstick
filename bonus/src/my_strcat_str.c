/*
** my_strcat.c for my_strcat.c in /home/Lyliya/CPool_Day07
**
** Made by Guillaume Guerin
** Login   <Lyliya@epitech.net>
**
** Started on  Tue Oct 11 10:38:37 2016 Guillaume Guerin
** Last update Tue Feb 14 16:57:37 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include "sfml.h"

char	*my_strcat_str(char *dest, char *src)
{
  int	i;
  int	j;
  char	*file;

  i = 0;
  j = 0;
  if ((file = malloc(sizeof(char) * (my_strlen(dest) +
				     my_strlen(src) + 2))) == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      file[i] = dest[i];
      i += 1;
    }
  while (src[j] != '\0')
    file[i++] = src[j++];
  file[i--] = '\0';
  return (file);
}

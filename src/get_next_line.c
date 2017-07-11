/*
** get_next_line.c for get_next_line in /home/lyliya/rendu/CPE/CPE_2016_getnextline
**
** Made by Guillaume
** Login   <lyliya@epitech.net>
**
** Started on  Mon Jan  2 13:54:58 2017 Guillaume
** Last update Mon Feb 27 14:43:09 2017 Guillaume Guerin
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i += 1;
  return (i);
}

char		*my_strcat(char *dest, char src)
{
  int		i;
  char		*cat;

  i = 0;
  if ((cat = malloc(sizeof(char) * (my_strlen(dest) + 2))) == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      cat[i] = dest[i];
      i += 1;
    }
  cat[i] = src;
  cat[++i] = '\0';
  free(dest);
  return (cat);
}

int	read_fill(int fd, char *buffer, int *nb_read, int *taille)
{
  if ((*nb_read = read(fd, buffer, READ_SIZE)) == -1)
    return (84);
  *taille = 0;
  buffer[*nb_read] = '\0';
  return (0);
}

char	*end_file(int nb_read, char *line)
{
  if (nb_read == 0 && my_strlen(line) == 0)
    return (free(line), NULL);
  else
    return (line);
}

char		*get_next_line(const int fd)
{
  int		back;
  char		*line;
  static char	buffer[READ_SIZE + 1];
  static int	nb_read = 0;
  static int	taille = 0;

  back = 0;
  if ((line = malloc(sizeof(*line))) == NULL)
    return (free(line), NULL);
  line[0] = '\0';
  while (back == 0)
    {
      if (taille >= nb_read)
	if ((read_fill(fd, buffer, &nb_read, &taille)) == 84)
	  return (free(line), NULL);
      if (buffer[taille] == '\0')
	return (end_file(nb_read, line));
      if ((line = my_strcat(line, buffer[taille])) == NULL)
	return (free(line), NULL);
      if (buffer[taille] == '\n')
	back = 1;
      taille += 1;
    }
  line[my_strlen(line) - 1] = '\0';
  return (line);
}

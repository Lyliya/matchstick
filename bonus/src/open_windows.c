/*
** open_windows.c for  in /home/lyliya/raytracer
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Fri Feb 10 11:40:43 2017 Guillaume Guerin
** Last update Mon Feb 13 17:23:28 2017 Guillaume Guerin
*/

#include <stdlib.h>
#include "sfml.h"

sfRenderWindow		*open_window(int width, int height)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "Window", sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

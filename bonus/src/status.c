/*
** status.c for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus/src
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Tue Feb 14 20:27:18 2017 Guillaume Guerin
** Last update Tue Feb 14 20:28:37 2017 Guillaume Guerin
*/

#include "sfml.h"

int	status(void)
{
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfFalse &&
      sfKeyboard_isKeyPressed(sfKeyRight) == sfFalse &&
      sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse &&
      sfKeyboard_isKeyPressed(sfKeyDown) == sfFalse &&
      sfKeyboard_isKeyPressed(sfKeyReturn) == sfFalse)
    return (0);
  return (1);
}

/*
** my_getnbr.c for my_getnbr.c in /home/Lyliya/CPool_Day04
**
** Made by Guillaume Guerin
** Login   <Lyliya@epitech.net>
**
** Started on  Fri Oct 14 11:26:03 2016 Guillaume Guerin
** Last update Tue Feb 14 16:41:39 2017 Guillaume Guerin
*/

int	my_getnbr(char *str)
{
  int	tab[3];

  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  while (str[tab[0]] > '\0')
    {
      if (!(str[0] <= 57 && str[0] >= 46) &&
	  !(str[0] == '-' || str[0] == '+'))
	return (-1);
      if (str[tab[0]] == '-')
	tab[2] += 1;
      if (str[tab[0]] >= 48 && str[tab[0]] <= 57)
	{
	  tab[1] = tab[1] * 10 + (str[tab[0]] - 48);
	}
      tab[0] += 1;
    }
  if (tab[1] < 0)
    return (0);
  if (tab[2] % 2 == 1)
    return (-tab[1]);
  else
    return (tab[1]);
}

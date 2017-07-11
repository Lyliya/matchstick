/*
** my.h for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Mon Feb 13 12:59:15 2017 Guillaume Guerin
** Last update Mon Feb 27 14:47:32 2017 Guillaume Guerin
*/

#ifndef MY_H_
# define MY_H_

# include "define.h"

typedef struct	s_board
{
  char		**board;
  int		max_st;
}		t_board;

typedef struct	s_ai
{
  int		gr;
  int		save;
  int		save_line;
  int		save_x;
}		t_ai;

typedef	struct	s_aimm
{
  int		ga_line;
  int		x;
}		t_aimm;

int		my_strlen(char *);
int		win_loose(char **);
void		aff_board(char **);
void		win(char **);
void		loose();
int		aff_line(int *, int *, int, t_board *);
int		my_putstr(char *);
char		*first_line(char *, int);
char		*line_func(char *, int, int);
char		**create_board(int);
int		my_getnbr(char *);
char		*get_next_line(const int);
char		**update_board(int, int, char **);
void		my_putnbr(int);
char		**player(t_board *, int, int *);
void		free_board(char **);
void		nb_err(int, int);
void		line_err(int, int);
int		grundy(t_board *);
int		nb_st(t_board *);
int		first_playable(t_board *);
void		reset(t_board *);
int		playable(t_board *, int);

char		**ai_f(t_board *, int);
void		main_ai(t_board *, t_ai *, t_aimm *, int);
char		**ai(t_board *, int);

#endif /* !MY_H_ */

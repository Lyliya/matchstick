/*
** my.h for  in /home/lyliya/raytracer
**
** Made by Guillaume Guerin
** Login   <lyliya@epitech.net>
**
** Started on  Fri Feb 10 11:39:12 2017 Guillaume Guerin
** Last update Tue Feb 14 21:21:34 2017 Guillaume Guerin
*/

#ifndef SFML_H_
# define SFML_H_

# include <SFML/Audio.h>
# include <SFML/Graphics.h>
# include <SFML/Window.h>

# define HELLO "Hello and, again, \nwelcome to\nAperture Science\n"
# define ATTACK "I took "
# define ATTACK2 " match(es)\nin line "

typedef struct		s_graph
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  sfColor		*color;
}			t_graph;

typedef struct		s_texture
{
  sfSprite		*playmenu;
  sfTexture		*playtexture;
  sfSprite		*rulesmenu;
  sfTexture		*rulestexture;
  sfSprite		*rulesopen;
  sfTexture		*opentexture;
  sfSprite		*linesprite;
  sfTexture		*linetexture;
  sfSprite		*bgsprite;
  sfTexture		*bgtexture;
  sfSprite		*cakesprite;
  sfTexture		*caketexture;
  sfSprite		*cakeoffsprite;
  sfTexture		*cakeofftexture;
  sfSprite		*gladossprite;
  sfTexture		*gladostexture;
  sfSprite		*pincesprite;
  sfTexture		*pincetexture;
  sfSprite		*brassprite;
  sfTexture		*brastexture;
  sfSprite		*speaksprite;
  sfTexture		*speaktexture;
  sfSprite		*wheatleysprite;
  sfTexture		*wheatleytexture;
  sfSprite		*spacesprite;
  sfTexture		*spacetexture;
  sfVector2f		pos;
  sfVector2f		scale;
  sfVector2f		gla_pos;
  sfVector2f		hand_pos;
  sfVector2f		hand_scale;
  sfVector2f		speak_pos;
  sfVector2f		speak_scale;
}			t_texture;

typedef struct		s_text
{
  sfFont		*font;
  sfText		*text;
}			t_text;

typedef struct		s_board
{
  char			**board;
  int			line;
  int			c_line;
  int			c_y;
  int			ia_line;
  int			ia_y;
}			t_board;

typedef struct		s_sound
{
  sfMusic		*music;
  sfMusic		*music2;
}			t_sound;

char			**create_board(int);
void			change_board(t_board *);
int			check_win(t_board *, int);
void			clearpixels(int, int, sfUint8 *);
void			draw(t_graph *);
void			draw_menu(t_graph *, int, t_texture *);
sfRenderWindow		*open_window(int, int);
int			my_strlen(char *);
void			my_put_pixel(int, int, sfColor);
char			*get_nbr(int);
int			choose_line(t_graph *, t_texture *);
int			line_menu(t_graph *, t_texture *, int *, t_text *);
void			draw_line(t_graph *, t_texture *, t_text *, int);
void			draw_game(t_graph *, t_texture *, t_board *);
int			m_game(t_graph *, t_texture *, int);
int			keyUp(t_texture *, t_board *);
int			keyDown(t_texture *, t_board *);
int			keyLeft(t_texture *, t_board *);
int			keyRight(t_texture *, t_board *);
int			keyReturn(t_board *);
void			bg_glad(t_graph *, t_texture *);
void			cake(t_graph *, t_texture *);
void			cakeoff(t_graph *, t_texture *);
void			pince(t_graph *, t_texture *);
void			rinit(t_texture *);
int			my_strlen(char *);
int			ai_game(t_board *);
void			new_board(int, int, t_board *);
char			*my_strcat_str(char *, char *);
void			speak(t_graph *, t_texture *, t_board *);
void			spaaaace(t_graph *, t_texture *);
int			status(void);

#endif /* !SFML_H_ */

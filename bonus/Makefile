##
## Makefile for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick/bonus
## 
## Made by Guillaume Guerin
## Login   <lyliya@epitech.net>
## 
## Started on  Mon Feb 13 17:17:54 2017 Guillaume Guerin
## Last update Tue Feb 14 20:28:15 2017 Guillaume Guerin
##

ECHO	=	echo -e

CC	=	gcc

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-I include

LDFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

RM	=	rm -f

NAME	=	matchstick

SRCS	=	src/main.c		\
		src/open_windows.c	\
		src/draw.c		\
		src/get_nbr.c		\
		src/line_menu.c		\
		src/m_game.c		\
		src/change_board.c	\
		src/keyboard.c		\
		src/draw_sprite.c	\
		src/ai_game.c		\
		src/my_strlen.c		\
		src/speak.c		\
		src/my_strcat_str.c	\
		src/spaaaace.c		\
		src/status.c		\
		src/display_board.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
	@$(ECHO) '\033[1;32m> Compiled\033[0m'

clean:
	$(RM) $(OBJS)
	@$(ECHO) '\033[1;35m> Directory cleaned\033[0m'

fclean:	clean
	$(RM) $(NAME)
	@$(ECHO) '\033[1;35m> Remove executable\033[0m'

re:	fclean all

.PHONY: all clean re

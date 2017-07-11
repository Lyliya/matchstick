##
## Makefile for  in /home/lyliya/rendu/CPE/CPE_2016_matchstick
## 
## Made by Guillaume Guerin
## Login   <lyliya@epitech.net>
## 
## Started on  Mon Feb 13 12:57:31 2017 Guillaume Guerin
## Last update Sun Feb 26 13:47:36 2017 Guillaume Guerin
##

ECHO	=	echo -e

CC	=	gcc

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-I include

RM	=	rm -f

NAME	=	matchstick

SRCS	=	src/get_next_line.c	\
		src/main.c		\
		src/my_getnbr.c		\
		src/display_board.c	\
		src/win_loose.c		\
		src/my_putstr.c		\
		src/my_putnbr.c		\
		src/ai.c		\
		src/player.c		\
		src/free_all.c		\
		src/error.c		\
		src/ai_form.c		\
		src/ai_function.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS)
	@$(ECHO) '\033[1;32m> Compiled\033[0m'

clean:
	$(RM) $(OBJS)
	@$(ECHO) '\033[1;35m> Directory cleaned\033[0m'

fclean:	clean
	$(RM) $(NAME)
	@$(ECHO) '\033[1;35m> Remove executable\033[0m'

re:	fclean all

.PHONY: all clean re

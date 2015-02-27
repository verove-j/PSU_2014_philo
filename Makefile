##
## Makefile for philosophe in /home/gazzol_j/rendu/PSU_2014_philo
## 
## Made by julien gazzola
## Login   <gazzol_j@epitech.net>
## 
## Started on  Mon Feb 23 09:32:08 2015 julien gazzola
## Last update Fri Feb 27 14:38:34 2015 julien gazzola
##

CC	=	gcc -g3

RM	=	rm -f

NAME	=	philo

SRC	=	init.c \
		philo.c

LDFLAGS	=	-lpthread -Wall -Wextra -Werror -pedantic -I. -ansi

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

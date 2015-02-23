##
## Makefile for philosophe in /home/gazzol_j/rendu/PSU_2014_philo
## 
## Made by julien gazzola
## Login   <gazzol_j@epitech.net>
## 
## Started on  Mon Feb 23 09:32:08 2015 julien gazzola
## Last update Mon Feb 23 09:35:57 2015 julien gazzola
##

CC	=	gcc

RM	=	rm -f

NAME	=	philo

SRC	=	main.c

LDFLAGS	=	-Wall -Wextra -Werror -pedantic -I. -ansi

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

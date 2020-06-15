##
## EPITECH PROJECT, 2018
## MyHunter
## File description:
## makefile for myhunter
##

SRC	=	src/main.c	\
		src/moving.c	\
		src/my_puts.c	\
		src/utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -g3 -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio -I include

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all
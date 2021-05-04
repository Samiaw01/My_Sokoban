##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compile libmy
##

SCR	=	$(wildcard lib/my/*.c)

OBJ	=	$(SCR:.c=.o)

LIB	=	lib/libmy.a

OBJ2	=	$(SRC:.c=.o)

SRC	=	$(wildcard *.c)

CFLAGS	=	-W -Wall -Wextra

FLAGS	=	-I./include -L./lib -lmy -lncurses

NAME	=	my_sokoban

all:	$(LIB) $(OBJ2)
		@$(CC) -o $(NAME) $(CFLAGS) $(OBJ2) $(FLAGS)

$(LIB):	$(OBJ)
		@$(AR) rsc $(LIB) $(OBJ)

clean:
		@$(RM) $(OBJ)
		@$(RM) *.~
		@$(RM) #*#
		@$(RM) *.o

fclean:	clean
		@$(RM) -f $(NAME)
		@$(RM) $(LIB)

re:		fclean all
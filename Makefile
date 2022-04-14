##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC		=	g++

LD		=	$(CC)

RM		=	rm -f

NAME		=	sort

PATH_INCLUDE	=	./include/

PATH_SRC	=	./src/

RWILDCARD	=	$(foreach d,$(wildcard $1*),$(call RWILDCARD,$d/,$2)\
$(filter $(subst *,%,$2),$d))

INCLUDE		=	-I$(PATH_INCLUDE)

CPPFLAGS		+=	$(INCLUDE) -g3 -W -Wall -Wextra -std=c++2a

SRC		=	$(call RWILDCARD,$(PATH_SRC),*.cpp)

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(LD) -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	$(RM) $(OBJ)
	rm -f *~
	rm -f *#

fclean:
	make clean
	$(RM) $(NAME)
	rm -f *.gcda
	rm -f *.gcno

re:	fclean all

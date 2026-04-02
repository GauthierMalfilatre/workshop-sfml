##
## EPITECH PROJECT, 2026
## WORKSHOP
## File description:
## Makefile
##

SRC = 	main.c \
		scenes/scene_menu.c \
		scenes/scene_pause.c \
		scenes/scene_game.c \

NAME 	= workshop
CFLAGS  = -Wall -Wextra
LDFLAGS = -lcsfml-graphics -lcsfml-window
CC      = gcc
OBJ     = $(SRC:.c=.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

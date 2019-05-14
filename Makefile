ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = otool

SRC_FILES = otool.c macho.c get_image.c dumphex.c

SRC_PATH = srcs/

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

OBJ = $(SRC:.c=.o)

LIB_NAME = -lft

LIB_PATH = libft/

INC = includes/

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RED = \033[31;44m
GREEN = \033[31;44m
ENDC = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB_PATH)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) ./libft/libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

clean:
	@(rm -f $(OBJ))

fclean: clean
	@(rm -f $(NAME) $(SYMLINK))
	@make -s -C $(LIB_PATH) fclean

re: fclean all

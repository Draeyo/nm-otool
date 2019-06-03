ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

OTOOL = otool

NM = nm

SRC_PATH = srcs/

NM_DIR = $(SRC_PATH)nm/

OTOOL_DIR = otool/

STATIC_DIR = static/

NM_FILES = $(NM_DIR)nm.c
		$(STATIC_FILES)

OTOOL_FILES = $(OTOOL_DIR)otool.c \
			$(OTOOL_DIR)macho.c \
			$(OTOOL_DIR)fat.c \
			$(OTOOL_DIR)dumphex.c \
			$(STATIC_FILES)

STATIC_FILES = $(STATIC_DIR)align.c \
			$(STATIC_DIR)swap_fat.c \
			$(STATIC_DIR)swap_mach.c \
			$(STATIC_DIR)swap_bytes.c \
			$(STATIC_DIR)save_filetype.c \
			$(STATIC_DIR)get_image.c \

SRC_FILES = $(NM_FILES) $(OTOOL_FILES)

OTOOL_SRC = $(OTOOL_FILES) $(STATIC_FILES)

NM_SRC = $(NM_FILES) $(STATIC_FILES)

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

OTOOL_OBJ = $(SRC:.c=.o)

NM_OBJ = $(SRC:.c=.o)

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

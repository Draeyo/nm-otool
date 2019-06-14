OTOOL = otool

NM = nm

SRC_PATH = srcs/

NM_DIR = srcs/nm/

OTOOL_DIR = srcs/otool/

STATIC_DIR = srcs/static/

NM_FILES = $(NM_DIR)nm.c \
			$(NM_DIR)macho.c \
			$(NM_DIR)fat.c \
			$(NM_DIR)save_filetype.c \
			$(NM_DIR)get_image.c \
			$(NM_DIR)align.c \
			$(NM_DIR)swap_fat.c \
			$(NM_DIR)swap_mach.c \
			$(NM_DIR)swap_bytes.c \
			$(NM_DIR)print.c \
			$(NM_DIR)print_nm.c \
			$(NM_DIR)sections.c \
			$(NM_DIR)get_result.c \

OTOOL_FILES = $(OTOOL_DIR)otool.c \
			$(OTOOL_DIR)macho.c \
			$(OTOOL_DIR)fat.c \
			$(OTOOL_DIR)dumphex.c \
			$(OTOOL_DIR)save_filetype.c \
			$(OTOOL_DIR)get_image.c \
			$(OTOOL_DIR)align.c \
			$(OTOOL_DIR)swap_fat.c \
			$(OTOOL_DIR)swap_mach.c \
			$(OTOOL_DIR)swap_bytes.c

SRC_FILES = $(NM_FILES) $(OTOOL_FILES)

OTOOL_SRC = $(OTOOL_FILES)

NM_SRC = $(NM_FILES)

SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))

OTOOL_OBJ = $(OTOOL_SRC:.c=.o)

NM_OBJ = $(NM_SRC:.c=.o)

LIB_NAME = -lft

LIB_PATH = libft/

INC = includes/

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RED = \033[31;44m
GREEN = \033[31;44m
ENDC = \033[0m

.PHONY: all clean fclean re

all: $(OTOOL) $(NM)

$(OTOOL): $(OTOOL_OBJ)
	@make -s -C $(LIB_PATH)
	@$(CC) $(CFLAGS) -o $@ $(OTOOL_OBJ) ./libft/libft.a

$(NM): $(NM_OBJ)
	@make -s -C $(LIB_PATH)
	@$(CC) $(CFLAGS) -o $@ $(NM_OBJ) ./libft/libft.a
	
$(OTOOL_OBJ):%.o: %.c
	@$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

$(NM_OBJ):%.o:%.c
	@$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

clean:
	@(rm -f $(NM_OBJ) $(OTOOL_OBJ))

fclean: clean
	@(rm -f $(NM) $(OTOOL))
	@make -s -C $(LIB_PATH) fclean

re: fclean all
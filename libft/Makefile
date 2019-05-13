NAME = libft.a

SRC_PATH = ./printf_srcs/

SRC_NAME = ft_calc_tag.c ft_conv_c.c ft_conv_d.c ft_conv_o.c ft_conv_p.c \
	  ft_conv_s.c ft_conv_tag.c ft_conv_u.c ft_conv_ws.c ft_conv_x.c \
	  ft_get_tag.c ft_itohex.c ft_itoo.c ft_nblen.c ft_noconv.c \
	  ft_padding.c ft_padding_int.c ft_padding_str.c ft_printf.c ft_putwchar_fd.c \
	  ft_s_atoi.c ft_strcut.c ft_strnewcpy.c ft_strupper.c ft_tag.c ft_uitooa.c \
	  ft_utility.c ft_uxtoa.c ft_valid.c ft_valid2.c ft_xtoa.c ft_xupper.c \
	  ft_utility2.c

LIBFT_PATH = ./libft_srcs/

LIBFT_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			 ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
			 ft_lstiter.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
			 ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
			 ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
			 ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
			 ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
			 ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
			 ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
			 ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
			 get_next_line.c ft_tabdup.c ft_tablen.c free_tab.c ft_print_mem.c
	  
CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INC)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME)) \
	  $(addprefix $(LIBFT_PATH),$(LIBFT_NAME))

OBJ = $(SRC:.c=.o)

INC = ./includes/

BL = \x1b[0m
RED = \x1b[31m
HRED = \x1b[1;31m
GREEN = \x1b[32m
HGREEN = \x1b[1;32m
HCYAN = \x1b[1;36;49m

all: $(NAME)

$(NAME): $(OBJ)
	@(/usr/bin/ar rc $(NAME) $(OBJ) && /usr/bin/ranlib $(NAME))
	@(echo "$(HCYAN)$(NAME)$(BL) $(GREEN)created.$(BL) $(HGREEN)✓$(BL)")

%.o: %.c
	@($(CC) -o $@ -c $< $(CFLAGS))

clean:
	@(/bin/rm -f $(OBJ))
	@(echo "$(HCYAN)$(NAME)$(BL) object files $(RED)cleaned.$(BL) $(HGREEN)✓$(BL)")


fclean:
	@(/bin/rm -f $(NAME))
	@(echo "$(HCYAN)$(NAME)$(BL) $(RED)deleted.$(BL) $(HGREEN)✓$(BL)")

re: fclean all

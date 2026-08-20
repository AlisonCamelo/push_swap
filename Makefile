NAME = push_swap

LIBFT_DIR = inc/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Se añadió la extensión .c que faltaba
SRC = main.c \
      src/parsing/parse_args.c \
      src/parsing/parse_nums.c \
      src/parsing/utils_stack.c \

OBJ = $(SRC:.c=.o)

# Se cambió $(LIBFT) por $(LIBFT_DIR) para incluir la carpeta de cabeceras correctamente
INCLUDE = -I. -I$(LIBFT_DIR)

RM = rm -f

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
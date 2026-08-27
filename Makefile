NAME = push_swap

LIBFT_DIR = inc/libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = #-Wall -Wextra -Werror

# Se añadió la extensión .c que faltaba
SRC = main.c \
      src/parsing/parse_args.c \
      src/parsing/parse_nums.c \
      src/parsing/utils_stack.c \
      src/metrics/disorder.c \
      src/metrics/indexing.c \
      src/movements/push_swap_ops.c \
      src/movements/rev_rotate_ops.c \
      src/movements/rotate_ops.c \
      src/benchmk/bench.c \
      src/benchmk/strategy.c \
      src/algorithm/strategy_complex.c \
      src/algorithm/strategy_medium.c \
      src/algorithm/strategy_simple.c \

OBJ = $(SRC:.c=.o)

# Se cambió $(LIBFT) por $(LIBFT_DIR) para incluir la carpeta de cabeceras correctamente
INCLUDE = -I./inc -I$(LIBFT_DIR)

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
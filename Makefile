NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c	\

OBJ = $(SRC:.c=.o)

INCLUDE = -I.

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
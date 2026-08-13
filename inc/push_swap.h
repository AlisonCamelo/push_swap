#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack 
{
    int value;
    struct s_tack *prev;
    struct s_stack *next;
} t_stack;

typedef struct s_flags
{
    int simple;
    int medium;
    int complex;
    int adaptative;
    int bench;
} t_flags;

void init_flags(t_flags *flags);
int check_flags(char *arg, t_flags flags);

#endif
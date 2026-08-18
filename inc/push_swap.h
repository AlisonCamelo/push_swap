#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>

# include "libft/libft.h"

typedef struct s_stack 
{
    int value;
    struct s_tack *prev;
    struct s_stack *next;
} t_stack;

typedef struct s_flags
{
    bool simple;
    bool medium;
    bool complex;
    bool adaptative;
    bool bench;
} t_flags;

void init_flags(t_flags *flags);
bool check_flags(char *arg, t_flags *flags);
int validate_argv(char **args);
int is_valid_number(char *str);


#endif
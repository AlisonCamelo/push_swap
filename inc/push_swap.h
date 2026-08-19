#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include "libft/libft.h"

typedef struct s_stack 
{
    int value;
    struct s_stack *prev;
    struct s_stack *next;
} t_stack;

typedef struct s_flags
{
    int simple;
    int medium;
    int complex;
    int adaptative;
    int bench;
    int has_flag;
    int parser_nums;
} t_flags;

// Util functions
void init_flags(t_flags *flags);
int check_flags(char *arg, t_flags *flags);
int validate_argv(char **args);
int is_valid_number(char *str);
int check_duplicates(t_stack *stack, int num);
void message_error();
t_stack *stack_new(int num);
void stack_add_back(t_stack **stack, t_stack *new_node);

// Algorithm utils

// Instruction functions
#endif
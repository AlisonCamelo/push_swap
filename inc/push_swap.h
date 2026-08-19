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

typedef struct s_movements
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_movements;
}	t_movements;

// Util functions
static void init_flags(t_flags *flags);
static int check_flags(char *argv, t_flags *flags);
static int check_valid_num(char *argv, char **list_str, t_flags *flags);
int is_valid_number(char *str);
void ft_error();
void ft_free(char **nums);
int check_duplicates(t_stack *stack, int num);
void message_error();
int	ft_join_args_with_space(char **list_str, char *args);
static void *ft_free_and_error(char **list_str);
t_stack *stack_new(int num);
void stack_add_back(t_stack **stack, t_stack *new_node);

// Algorithm utils

// Instruction functions
#endif
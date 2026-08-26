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
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_flags
{
    int simple;
    int medium;
    int complex;
    int adaptative;
    int bench;
} t_flags;

//Funciones para parsing, conversion y validación
static void init_flags(t_flags *flags);
static void handle_error(t_stack **stack_a);
int parse_args(int argc, char **argv, t_stack **stack_a, t_flags *flags);
static int process_flags(char *arg, t_flags *flags);
static int parse_str_argv(char *arg, t_stack **stack_a);
static int	process_nums(char *token, t_stack **stack_a);
static int	ft_is_digit(char c);
int	ft_is_valid_number(const char *str, int *out_val);
int check_duplicates(t_stack *stack, int num);

//Utiles para listas enlazadas y memoria 
t_stack *stack_new(int num);
void stack_add_back(t_stack **stack, t_stack *new_node);
void free_stack(t_stack **stack);
void free_split(char **split);

//Indexación y Métrica de Desorden
int		ft_stack_size(t_stack *stack);
void	assign_indexes(t_stack *stack);
int	calculate_disorder(t_stack *stack);
int		is_sorted(t_stack *stack);

//Funciones utiles para los movimientos
int	sa(t_stack **stack_a);
int	sb(t_stack **stack_b);
int	ss(t_stack **stack_a, t_stack **stack_b);
int	pa(t_stack **stack_a, t_stack **stack_b);
int	pb(t_stack **stack_a, t_stack **stack_b);
int	ra(t_stack **stack_a);
int	rb(t_stack **stack_b);
int	rr(t_stack **stack_a, t_stack **stack_b);
int	rra(t_stack **stack_a);
int	rrb(t_stack **stack_b);
int	rrr(t_stack **stack_a, t_stack **stack_b);

// Algorithm utils
void	sort_three(t_stack **stack_a);
int		sort_simple(t_stack **stack_a, t_stack **stack_b);
int	sort_medium(t_stack **stack_a, t_stack **stack_b);
int	sort_complex(t_stack **stack_a, t_stack **stack_b);
int		run_strategy(t_stack **a, t_stack **b, t_flags *fl, int disorder);
void	print_bench(t_flags *flags, int disorder, int ops, char *strat);

#endif
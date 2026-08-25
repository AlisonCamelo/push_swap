/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:24:38 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/25 18:24:52 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ordena exactamente 3 elementos en máximo 2 movimientos
void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

// Busca la distancia del nodo con el índice indicado desde la cima
static int	get_distance(t_stack *stack, int target_index)
{
	int	dist;

	dist = 0;
	while (stack)
	{
		if (stack->index == target_index)
			break ;
		dist++;
		stack = stack->next;
	}
	return (dist);
}

// Algoritmo de selección general para --simple (y para 4/5 elementos)
int	sort_simple(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	ops;

	size = ft_stack_size(*stack_a);
	if (size == 2 && (*stack_a)->index > (*stack_a)->next->index)
		return (sa(stack_a));
	if (size == 3)
		return (sort_three(stack_a), 1);
	pushed = 0;
	ops = 0;
	while (size - pushed > 3)
	{
		if (get_distance(*stack_a, pushed) <= (size - pushed) / 2)
			while ((*stack_a)->index != pushed)
				ops += ra(stack_a);
		else
			while ((*stack_a)->index != pushed)
				ops += rra(stack_a);
		ops += pb(stack_a, stack_b);
		pushed++;
	}
	sort_three(stack_a);
	while (pushed-- > 0)
		ops += pa(stack_a, stack_b);
	return (ops);
}
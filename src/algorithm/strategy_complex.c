/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:27:03 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/26 12:34:47 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calcula cuántos bits son necesarios para representar el índice más grande
static int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = ft_stack_size(stack) - 1;
	bits = 0;
	while ((max >> bits) > 0)
		bits++;
	return (bits);
}

// Algoritmo Radix Sort bit a bit
int	sort_complex(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_bits;
	int	bit;
	int	i;
	int	ops;

	size = ft_stack_size(*stack_a);
	max_bits = get_max_bits(*stack_a);
	bit = 0;
	ops = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->index >> bit) & 1) == 0)
				ops += pb(stack_a, stack_b);
			else
				ops += ra(stack_a);
			i++;
		}
		while (*stack_b)
			ops += pa(stack_a, stack_b);
		bit++;
	}
	return (ops);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_medium.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:26:22 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/25 18:26:27 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calcula la cantidad óptima del tamaño de bloque según N
static int	get_chunk_size(int size)
{
	if (size <= 20)
		return (4);
	if (size <= 100)
		return (15);
	return (30);
}

// Fase 1: Empujar elementos de A a B por rangos (chunks)
static int	push_chunks_to_b(t_stack **a, t_stack **b, int size, int chunk)
{
	int	i;
	int	ops;

	i = 0;
	ops = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			ops += pb(a, b);
			ops += rb(b);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			ops += pb(a, b);
			i++;
		}
		else
			ops += ra(a);
	}
	return (ops);
}

// Busca la posición del elemento con el índice máximo en B
static int	find_max_pos(t_stack *b, int max_idx)
{
	int	pos;

	pos = 0;
	while (b)
	{
		if (b->index == max_idx)
			return (pos);
		pos++;
		b = b->next;
	}
	return (0);
}

// Fase 2: Devolver de B a A seleccionando siempre el máximo
int	sort_medium(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk;
	int	ops;
	int	max_idx;
	int	pos;

	size = ft_stack_size(*stack_a);
	chunk = get_chunk_size(size);
	ops = push_chunks_to_b(stack_a, stack_b, size, chunk);
	while (*stack_b)
	{
		max_idx = ft_stack_size(*stack_b) - 1;
		pos = find_max_pos(*stack_b, max_idx);
		if (pos <= ft_stack_size(*stack_b) / 2)
			while ((*stack_b)->index != max_idx)
				ops += rb(stack_b);
		else
			while ((*stack_b)->index != max_idx)
				ops += rrb(stack_b);
		ops += pa(stack_a, stack_b);
	}
	return (ops);
}
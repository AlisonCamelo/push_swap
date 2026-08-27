/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:34:09 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/26 13:03:49 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **stack_a)
{
    t_stack *last;
    t_stack *first;

    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return(0);
    last = NULL;
    first = *stack_a;
    while(first->next)
    {
        last = first;
        first = first->next;
    }
    last->next = NULL;
    first->next = *stack_a;
    *stack_a = first;
    write(1, "rra\n", 4);
    return(1);
}

int	rrb(t_stack **stack_b)
{
    t_stack *last;
    t_stack *first;

    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return(0);
    last = NULL;
    first = *stack_b;
    while(first->next)
    {
        last = first;
        first = first->next;
    }
    last->next = NULL;
    first->next = *stack_b;
    *stack_b = first;
    write(1, "rrb\n", 4);
    return(1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	moved;

	moved = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
		moved += rra(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		moved += rrb(stack_b);
	return (moved);
}
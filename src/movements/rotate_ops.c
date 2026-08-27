/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:34:11 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/26 12:38:25 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **stack_a)
{
    t_stack *first;
    t_stack *last;

    while(!stack_a || !*stack_a || !(*stack_a)->next)
        return(0);
    first = *stack_a;
    *stack_a = first->next;
    first->next = NULL;
    last = *stack_a;
    while(last->next)
        last = last->next;
    last->next = first;
    write(1, "ra\n", 3);
    return(1);
}
int	rb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *last;
    
    while(!stack_b || !*stack_b || !(*stack_b)->next)
        return(0);
    first = *stack_b;
    *stack_b = first->next;
    first->next = NULL;
    last = *stack_b;
    while(last->next)
        last = last->next;
    last->next = first;
    write(1, "rb\n", 3);
    return(1);
}
int	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	moved;

	moved = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
		moved += ra(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		moved += rb(stack_b);
	return (moved);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:34:06 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/21 13:12:39 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	sa(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;
    
    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return(0);
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
    write(1, "sa\n", 3);
    return(1);
}
int	sb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *second;

    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return(0);
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
    write(1, "sb\n", 3);
    return(1);
}
int	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	moved;

	moved = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
		moved += sa(stack_a);
	if (stack_b && *stack_b && (*stack_b)->next)
		moved += sb(stack_b);
	if (moved > 0)
		write(1, "ss\n", 3);
	return (moved);
}
int	pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *jump;

    if(!stack_b || !*stack_b)
        return(0);
    jump = *stack_b;
    *stack_b = (*stack_b)->next;
    jump->next = *stack_a;
    *stack_a = jump;
    write(1, "pa\n", 3);
    return(1);
}
int	pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *jump;

    if(!stack_a || !*stack_a)
        return(0);
    jump = *stack_a;
    *stack_a = (*stack_a)->next;
    jump->next = *stack_a;
    *stack_a = jump;
    write(1, "pb\n", 3);
}
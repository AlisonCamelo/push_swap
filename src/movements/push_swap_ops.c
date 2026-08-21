/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 10:34:06 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/21 11:03:16 by acamelo          ###   ########.fr       */
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
int	pa(t_stack **stack_a, t_stack **stack_b)
{

}
int	pb(t_stack **stack_a, t_stack **stack_b)
{
    
}
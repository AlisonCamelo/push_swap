/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:47:55 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 20:57:39 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// Retorna la cantidad de nodos en la lista
int	ft_stack_size(t_stack *stack)
{
    int size;
    
    size = 0;
    while(stack)
    {
        size++;
        stack = stack->next;
    }
    return(size);
}
// Asigna a cada nodo un índice de 0 a N-1 según su valor relativo
void	assign_indexes(t_stack *stack)
{
    t_stack *current;
    t_stack *runner;
    int count;

    current = stack;
    while(current)
    {
        count = 0;
        runner = stack;
        while(runner)
        {
            if(runner->value < current->value)
                count++;
            runner = runner->next;
        }
        current->index = count;
        current = current->next
    }
}
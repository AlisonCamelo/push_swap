/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:47:39 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/26 12:37:53 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_inversions(t_stack *stack)
{
    t_stack *i;
    t_stack *j;
    int inversions;

    inversions = 0;
    i = stack;
    while(i)
    {
        j = i->next;
        while(j)
        {
            if(i->value > j->value)
                inversions++;
            j = j->next;
        }
        i = i->next;
    }
    return(inversions);
}
// Devuelve el porcentaje de desorden de 0 a 100 (int)
int	calculate_disorder(t_stack *stack)
{
    int size;
    int inversions;
    int max_inversions;

    size = ft_stack_size(stack);
    if(size < 1)
        return(0);
    inversions = count_inversions(stack);
    max_inversions = (size * (size - 1)) / 2;
    if(max_inversions == 0)
        return(0);
    return((inversions * 100) / max_inversions);
}
// Comprueba si la lista ya está completamente ordenada
int is_sorted(t_stack *stack)
{
    if(!stack)
        return(1);
    while(stack->next)
    {
        if(stack->value > stack->next->value)
            return(0);
        stack = stack->next;
    }
    return(1);
}
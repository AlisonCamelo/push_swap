/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 20:47:39 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 21:11:22 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// Devuelve el porcentaje de desorden de 0 a 100 (int)
int	calculate_disorder(t_stack *stack)
{
    
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
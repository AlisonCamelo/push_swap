/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 16:44:26 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/18 18:43:38 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int check_duplicates(t_stack *stack, int num)
{
    //mientras que stack no sea null
    while(stack != NULL)
    {
        if(stack->value == num)
            return(1); //Devuelve 1 cuando esta duplicado
        stack = stack->next; // continua recorriendo ("siguiente caja")
    }
    return(0);//no hay duplicados
}
//funcion que crea y retorna un nuevo nodo
t_stack *stack_new(int num)
{
    t_stack *new_node;
    
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return(NULL);
    new_node->value = num;//
    new_node->prev = NULL;
    new_node->next = NULL;
    return(new_node);
}
t_stack *stack_add_back(t_stack **stack, t_stack *new_node)
{
    t_stack *last;
    
    if (!stack || !new_node)
        return ;
    if (*stack ==  NULL)
    {
        *stack = new_node;
        return ;
    }    

}
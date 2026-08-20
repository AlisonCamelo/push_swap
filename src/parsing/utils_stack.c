/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:14:10 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 21:02:11 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

//funcion que crea y retorna un nuevo nodo
t_stack *stack_new(int num)
{
    t_stack *node;
    
    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return(NULL);
    node->value = num;
    node->index = -1;
    node->next = NULL;
    return(node);
}
void stack_add_back(t_stack **stack, t_stack *new_node)
{
    t_stack *last;
    
    if (!stack || !new_node)
        return ;
    if (*stack ==  NULL)
    {
        *stack = new_node;
        return ;
    }
    last = *stack;
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
}
void free_stack(t_stack **stack)
{
    t_stack *tmp;
    
    if(!stack || !*stack)
        return;
    while(*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    } 
    *stack = NULL;
}
void free_split(char **split)
{
    int i;
    
    if(!split)
        return ;
    i = 0;
    while(split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

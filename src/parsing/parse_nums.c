/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pushswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 16:44:26 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 17:55:30 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
int	ft_is_valid_number(const char *str, int *out_val)
{
	int			i, sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		res = (res * 10) + (str[i] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			return (0);
		i++;
	}
	*out_val = (int)(res * sign);
	return (1);
}

int check_duplicates(t_stack *stack, int num)
{
    //mientras que stack no sea null
    while(stack)
    {
        if(stack->value == num)
            return(1); //Devuelve 1 cuando esta duplicado
        stack = stack->next; // continua recorriendo ("siguiente caja")
    }
    return(0);//no hay duplicados
}
//funcion que crea y retorna un nuevo nodo
/*t_stack *stack_new(int num)
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
    new_node->prev = last;
}*/
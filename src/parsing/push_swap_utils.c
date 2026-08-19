/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 16:44:26 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/19 17:59:53 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// Devuelve 1 si es un número válido, 0 si no lo es
int is_valid_number(char *str)
{
    int j;

    j = 0;
    //Si empieza por '+' o '-', saltamos ese carácter
    if(str[j] == '-' || str[j] == '+')
        j++;
    //Si era SOLO "+" o "-" y no hay dígitos después no es valido
    if(str[j] == '\0')
    return(0);
    //Revisamos hasta el final de la cadena ('\0')
    while(str[j] != '\0')
    {
        //Si hay algo que NO es un número entre '0' y '9' no es valido
        if(!ft_isdigit(str[j]))
            return(0);
        j++;
    }
    //al good
    return(1);
}
void ft_error()
{
    write(2, "Error\n", 6);
}
void ft_free(char **nums)
{
    int i;

    i = 0;
    if (!nums)
		return ;
	while (nums[i])
		free(nums[i++]);
	free(nums);
}
int	ft_join_args_with_space(char **list_str, char *args)
{
	char	*temp;
	char	*str;
	//Unimos el argumento actual con un espacio al final
	str = ft_strjoin(args, " ");
	if (!str)
		return (0);
    //Guardamos la cadena vieja para no perder su puntero
	temp = *list_str;
	//Unimos lo que teníamos acumulado con el nuevo argumento+espacio
	*list_str = ft_strjoin(temp, str);
	//Liberamos la memoria intermedia para evitar leaks
	free(str);
	free(temp);
	//Verificamos que la unión final no haya fallado
	if (!*list_str)
		return (0);
	return (1);
}
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
}
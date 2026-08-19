/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldpush_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:42:08 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/19 21:00:40 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_flags flags;
    char    **args; // array de strings
    int     i, j;
    
    //Si no hay suficientes argumentos, return(0);
    if (argc < 2)
        return(-1);
    //inicializa flags y punteros
    stack_a = NULL;
    stack_b = NULL;
    init_flags(&flags);
    i = 1;
    while(argv[i] != NULL)
    {
        //chequea flags, si es, guardamos y continuamos
        if (check_flags(argv[i], &flags))
        {
            i++;
            continue ;
        }
        //si esta aqui es un numero o una cadena de ellos
        args = ft_split(argv[i], ' ');
        if (!validate_argv(args))//validar sintaxis y rango
        {
            message_error(); // Imprime "Error\n"
            return(1);      // Termina el programa inmediatamente
        }
        j = 0;
        while(args[j] != NULL)
        {
            if(check_duplicates(stack_a, (int)ft_atol(args[j])))
            {
                message_error();
                // Aquí luego liberaremos memoria de stack_a y args
                return(1);
            }
            stack_add_back(&stack_a, stack_new((int)ft_atol(args[j])));
        }
    i++;
    }
    return(0);
}

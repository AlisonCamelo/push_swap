/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:02:22 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 20:40:29 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

//inicilizar flags
static void init_flags(t_flags *flags)
{
    flags->simple = 0;
    flags->medium = 0;
    flags->complex = 0;
    flags->adaptative = 0;
    flags->bench = 0;
}
static void handle_error(t_stack **stack_a)
{
    free_stack(stack_a);
    write(2, "Error\n", 6);
    exit(1);
}
int main(int argc, char **argv)
{
    t_stack	*stack_a;
	t_flags	flags;
    double	disorder;

    if(argc < 2)
        return(0);
    stack_a = NULL;
    init_flags(&flags);
    if(!parse_args(argc, argv, &stack_a, &flags))
            handle_error(&stack_a);
    if(!stack_a)
        return(0); //si ya paso por todo esto, el parsing ya ha terminado
    assing_indexes(stack_a);//Asignar índices de 0 a N-1
    if(is_sorted(stack_a)) //Si ya está ordenada (Desorden 0.0), salir sin emitir instrucciones
        return(free_stack(&stack_a), 0);
    disorder = calculate_disorder(stack_a);//Calcular Métrica de Desorden para la estrategia adaptativa / bench
    
    free_stack(&stack_a);
    return(0);
}

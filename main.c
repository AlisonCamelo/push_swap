/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:02:22 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 19:38:07 by acamelo          ###   ########.fr       */
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

    if(argc < 2)
        return(0);
    stack_a = NULL;
    init_flags(&flags);
    if(!parse_args(argc, argv, &stack_a, &flags))
            handle_error(&stack_a);
    if(!stack_a)
        return(0);
    /* El parsing ha finalizado con éxito.
	** Siguiente paso: Indexación y Cálculo del Disorder Metric.
	*/
    free_stack(&stack_a);
    return(0);
}

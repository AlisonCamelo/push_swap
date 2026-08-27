/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:02:22 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/27 10:55:08 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//inicilizar flags
void init_flags(t_flags *flags)
{
    flags->simple = 0;//todas empezaran en cero, esto para que no contengan informacion basura redeterminada y facilitar luego el codigo
    flags->medium = 0;
    flags->complex = 0;
    flags->adaptative = 1;
    flags->bench = 0;
}
void handle_error(t_stack **stack_a)
{
    free_stack(stack_a);//libera memoria del stack
    write(2, "Error\n", 6);//escribe error en pantalla
    exit(1);//termina
}

int main(int argc, char **argv)
{
    t_stack	*stack_a;
	t_stack	*stack_b;
	t_flags	flags;
    int	disorder;

    if(argc < 2)//si solo nombre del programa o un argumento
        return(0);//error
    stack_a = NULL;//stacks empiezan en NULL
    stack_b = NULL;//
    init_flags(&flags);//inicializar flags
    if(!parse_args(argc, argv, &stack_a, &flags))//si no se pudo hacer el parseo de los argumentos
            handle_error(&stack_a);//libera memoria y muestra error en pantalla
    if(!stack_a)
        return(0); //si ya paso por todo esto, el parsing ya ha terminado
    assign_indexes(stack_a);//Asignar índices de 0 a N-1
    if(is_sorted(stack_a)) //Si ya está ordenada (Desorden 0.0), salir sin emitir instrucciones
        return(free_stack(&stack_a), 0);
    disorder = calculate_disorder(stack_a);//Calcular Métrica de Desorden para la estrategia adaptativa / bench
    run_strategy(&stack_a, &stack_b, &flags, disorder);
	free_stack(&stack_a);
	free_stack(&stack_b);
    return(0);
}

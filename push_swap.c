/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:42:08 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/14 12:05:34 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

//Inicializando flags a 0
void init_flags(t_flags *flags)
{
    flags->simple = 0;
    flags->medium = 0;
    flags->complex = 0;
    flags->adaptative = 0;
    flags->bench = 0;    
}

// funcion que se encarga unicamente de detectar flags
int check_flags(char *arg, t_flags *flags)
{
    if (ft_strcmp(arg, "--simple") == 0)
        return (flags->simple = 1, 1);
    if (ft_strcmp(arg, "--medium") == 0)
        return (flags->medium = 1, 1);
    if (ft_strcmp(arg, "--complex") == 0)
        return (flags->complex = 1, 1);
    if (ft_strcmp(arg, "--adaptive") == 0)
        return (flags->adaptative = 1, 1);
    if (ft_strcmp(arg, "--bench") == 0)
        return (flags->bench = 1, 1);
    return(0);
}

int clean_numbers(char **argv)
{
    
}
int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_flags flags;
    int i;

    //Si no hay suficientes argumentos, return(0);
    if (argc < 2)
        return(0);
    //inicializa flags y punteros
    stack_a = NULL;
    stack_b = NULL;
    init_flags(&flags);
    i = 1;
    while(argv[i] != NULL)
    {
        //chequea flags
        if (check_flags(argv[i], &flags))
        {
        //procesaremos las cadenas de números (Paso 3.3 y 3.4)
        //llamaremos a tu función clean_numbers / validate
            i++;
        }
    }
    return(0);
}
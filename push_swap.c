/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:42:08 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/14 12:00:18 by acamelo          ###   ########.fr       */
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

    i = 1;
    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return(0);
    init_flags(&flags);
    while(argv[i] != NULL)
    {
        if (check_flags(argv[i], &flags))
        {
            i++;
            
        }
    }
    var = validate_argv(argv);
    if (var == 1)
        ft_printf("Error");
    else 
        ft_printf("GOOD");
}
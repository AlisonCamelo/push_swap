/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_valid_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:23:44 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 17:36:25 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

//chequea flags e implementa las estrategias
static int process_flags(char *arg, t_flags *flags)
{
    if (ft_strcmp(arg, "--simple") == 0)
        return (flags->simple = 1, 1);
    else if (ft_strcmp(arg, "--medium") == 0)
        return (flags->medium = 1, 1);
    else if (ft_strcmp(arg, "--complex") == 0)
        return (flags->complex = 1, 1);
    else if (ft_strcmp(arg, "--adaptive") == 0)
        return (flags->adaptative = 1, 1);
    else if (ft_strcmp(arg, "--bench") == 0)
        return (flags->bench = 1, 1);
    else 
        return(0);
    return(1);
}
static int parse_str_argv(char *arg, t_stack **stack_a)
{
    char **nums;
    int i;
 
    nums = ft_split(arg, ' ');
    if(!nums || !*nums) // split fallo? retorna
        return(free_split(nums), 0);
    i = 0;
    while(nums[i])
    {
        if(!is_valid_number(nums[i++]))//pasa nums[i] a is_valid_number y luego incrementa para la siguiente vuelta al buble
            return(ft_free(nums), 0); //si falla libera memoria y retorna(0)
    }
    ft_free(nums); //libera todo el split(ya valido todos los textos)
}

int parse_args(int argc, char **argv, t_stack **stack_a, t_flags *flags)
{
    int i;

    i = 1;
    while(i < argc)
    {
        if(argv[i][0] == '-' && argv[i][1] == '-')
        {
            if(!process_flags(argv[i], flags))
                return(0);
            
        }
        else
        {
            if(!parse_str_argv(argv[i], stack_a))
                return(0);
        }
        i++;
    }
    return(1);
}

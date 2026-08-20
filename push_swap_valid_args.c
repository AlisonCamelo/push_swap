/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_valid_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:23:44 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 17:40:51 by acamelo          ###   ########.fr       */
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
static int	process_nums(char *num, t_stack **stack_a)
{
    int     val;
    t_stack *new_node;
    
    if(!ft_atol(num, val))
        return(0);
    
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
        if(!process_nums(nums[i], stack_a))
            return(free_split(nums), 0);
        i++;
    }
    free_split(nums); 
    return(1);
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

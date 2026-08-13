/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:42:08 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/13 17:53:12 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"


int push_swap(char *argv)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        while((argv[i] >= '0' && argv[i] <= '9'))
            i++;
        return(0);
    }
    return(1);    
}
int check_flags(char *arg, t_flags flags)
{
    if (ft_strcmp(arg, "--simple") == 0)
        return (flags->simple = 1, 1);
    if (ft_strcmp(arg, "--medium") == 0)
        return (flags->medium = 1, 1);
    if (ft_strcmp(arg, "--complex") == 0)
        return (flags->complex = 1, 1);
    if (ft_strcmp(arg, "--adaptive") == 0)
        return (flags->adaptive = 1, 1);
    if (ft_strcmp(arg, "--bench") == 0)
        return (flags->bench = 1, 1);
    return(0);
}
int main(int argc, char **argv)
{
    int var;

    if (argc < 2)
        return(0);
    var = validate_argv(argv);
    if (var == 1)
        ft_printf("Error");
    else 
        ft_printf("GOOD");
}
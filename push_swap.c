/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:42:08 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/12 18:16:17 by acamelo          ###   ########.fr       */
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
int main(int argc, char **argv)
{
    int var;

    if (argc < 2)
    {
        ft_printf("ERROR");
        return(1);
    }
    var = validate_argv(*argv);
    if (var == 1)
        ft_printf("Error");
    else 
        ft_printf("GOOD");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 21:02:22 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/19 21:02:35 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int main(int argc, char **argv)
{
    t_movements *move;
    t_flags flags;
    int i;
    
    if (argc > 1)
    {
        init_flags(&flags);
        i = 1;
        while (argv[i] != NULL)
        {
            if(check_flags(argv[i], &flags));
        }
    }    
    ft_error();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 18:16:32 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/14 13:47:06 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

int validate_argv(char **args)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if((args[i][j] == '-' && args[i++][j++] == '-'))
    while (args[i] != NULL)
    {
        if(args[i][j] == '-' || args[i][j] == '+')
    
    }
    i++;
}
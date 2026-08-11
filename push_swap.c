/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:42:08 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/11 18:30:04 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

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
        return(0);
    else 
        var = push_swap(*argv);
    if (var == 1)
        printf("Error");
    else 
        printf("GOOD");
}
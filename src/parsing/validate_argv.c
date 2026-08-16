/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 18:16:32 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/16 17:01:51 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

int is_valid_number(char *str)
{
    
}

int validate_argv(char **args)
{
    int i;

    i = 0;
    //recorremos string por string hasta llegar a NULL
    while(args[i] != NULL)
    {
        //Pasamos el string actual a la funcion is_valid_numbers+
        if(!is_valid_number(args[i]))
            return(0); //si falla devuelve error
        i++;
    }
    return(1); //todos los string args son validos
}
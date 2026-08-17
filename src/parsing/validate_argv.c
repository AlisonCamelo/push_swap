/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 18:16:32 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/17 18:40:46 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// Devuelve 1 si es un número válido, 0 si no lo es
int is_valid_number(char *str)
{
    int j;

    j = 0;
    //Si empieza por '+' o '-', saltamos ese carácter
    if(str[j] == '-' || str[j] == '+')
        j++;
    //Si era SOLO "+" o "-" y no hay dígitos después no es valido
    if(str[j] == '\0')
    return(0);
    //Revisamos hasta el final de la cadena ('\0')
    while(str[j] != '\0')
    {
        //Si hay algo que NO es un número entre '0' y '9' no es valido
        if(!ft_isdigi(str[j]))
            return(0);
        j++;
    }
    //al good
    return(1);
}

int validate_argv(char **args)
{
    int i;
    long num;

    i = 0;
    //recorremos string por string hasta llegar a NULL
    while(args[i] != NULL)
    {
        //Pasamos el string actual a la funcion is_valid_numbers
        if(!is_valid_number(args[i]))
            return(0); //si falla devuelve error
        //Convertimos a long con ft_atol
        num = ft_atol(args[i]);
         //verificando que el int quepa en 32 bits
        if(num < INT_MIN || num > INT_MAX) //CHECKKKKKKK!!!!!!! CHEQUEAR
            return(0);
        i++;
    }
    return(1); //todos los string args son validos
}
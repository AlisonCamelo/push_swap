/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 17:42:08 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/18 13:55:35 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

//Funcion de error
void message_error()
{
    write(2, "Error\n", 6);
}

//Inicializando flags a 0
void init_flags(t_flags *flags)
{
    flags->simple = false;
    flags->medium = false;
    flags->complex = false;
    flags->adaptative = false;
    flags->bench = false;    
}

// funcion que se encarga unicamente de detectar flags
bool check_flags(char *arg, t_flags *flags)
{
    if (strcmp(arg, "--simple") == false)
        return (flags->simple = 1, 1);
    if (strcmp(arg, "--medium") == 0)
        return (flags->medium = 1, 1);
    if (strcmp(arg, "--complex") == 0)
        return (flags->complex = 1, 1);
    if (strcmp(arg, "--adaptive") == 0)
        return (flags->adaptative = 1, 1);
    if (strcmp(arg, "--bench") == 0)
        return (flags->bench = 1, 1);
    return(0);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_flags flags;
    char    **args; // array de strings
    int     i;
    
    //Si no hay suficientes argumentos, return(0);
    if (argc < 2)
        return(1);


        
    //inicializa flags y punteros
    stack_a = NULL;
    stack_b = NULL;
    init_flags(&flags);
    i = 1;
    while(argv[i] != NULL)
    {
        //chequea flags, si es, guardamos y continuamos
        if (check_flags(argv[i], &flags))
        {
            i++;
            continue ;
        }
        //si esta aqui es un numero o una cadena de ellos
        args = ft_split(argv[i], ' ');
        validate_argv(args);
        // Recorrer 'args', validar e insertar en stack_a
        // No olvidar liberar 'args' al terminar ese grupo
    i++;
    }
    return(0);
}

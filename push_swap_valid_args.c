/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_valid_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:23:44 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 17:31:36 by acamelo          ###   ########.fr       */
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
//funcion que determina si los argumentos son numeros validos a demas una ves hace el split y los demas chequeos
//hace un join que lo que permite es unir argumento por argumento al final de la lista list_str seguido de un espacio
static int check_valid_num(char *argv, char **list_str, t_flags *flags)
{
    char **nums;
    int i;
    while(*argv == ' ') //si hay espacios, continua, esto por si alguien solo manda espacios como argumentos
        argv++;
    if(!*argv) //si argv se quedo vacio return(0)
        return(0);
    nums = ft_split(argv, ' ');
    if(!nums) // split fallo? retorna
        return(0);
    i = 0;
    while(nums[i])
    {
        if(!is_valid_number(nums[i++]))//pasa nums[i] a is_valid_number y luego incrementa para la siguiente vuelta al buble
            return(ft_free(nums), 0); //si falla libera memoria y retorna(0)
    }
    ft_free(nums); //libera todo el split(ya valido todos los textos)
    if(flags->parser_nums == 1) // si hubo algun error de logica/etc..
        return(0); //hubo error retorna 0
    flags->parser_nums = 0; //si por el contraro no hubo error al leer nada parser sera 0
    return(1); //se ha completado con exito
}
//funcion que muestra error y que libera memoria si aun no ha sido liberada correctamente
static void *ft_free_and_error(char **list_str)
{
    write(2, "Error\n", 6);
    if(list_str && *list_str)
    {
        free(*list_str);
        *list_str = NULL;
    }
    return(NULL);
}
 //
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

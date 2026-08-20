/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_valid_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:23:44 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/20 17:27:34 by acamelo          ###   ########.fr       */
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

    args = argv;
    list_str = ft_strdup("");//inicializa una cadena vacia
    if (!list_str)//si no funciona retrna NULL
        return(NULL);
    init_flags(&flags); //inicializa flags
    while(*args) // mientras args exista
    {
        if(!check_flags(*args, flags) &&  //si no hay flags y no hay numeros validos 
                !check_valid_num(*args, &list_str, flags))
                return(ft_free_and_error(&list_str), 1); // libera el espacio y retorna error
        args++; //si todo va bien continua iterando en los argumentos y sigue chequeando las flags y los numeros
    }
    if(flags->simple + flags->medium + flags->complex == 0) //si la suma de las flags es cero eso quiere decir que no han puesto flags
        flags->adaptative = 1; // por lo tanto debe elegirse adaptaive por defecto
    if (!ft_indexator(list_str, &list_index, flags))
		return (ft_error_handler(&list_str), NULL);
	return (free(list_str), list_index);
}

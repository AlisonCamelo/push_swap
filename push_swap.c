/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:23:44 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/19 17:43:04 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static void init_flags(t_flags *flags)
{
    //parser_nums = -1 no ha leido nada el programa.
    // 0 = el programa esta leyendo las flags del inicio
    // 1 = el programa ha encontrado y leido numeros, 
    //si luego hay flags en medio hay errores
    flags->parser_nums = -1;
    flags->simple = 0;
    flags->medium = 0;
    flags->complex = 0;
    flags->adaptative = 0;
    flags->bench = 0;
    flags->has_flag = 0; //1 hay flags, 0 no hay
}
static int check_flags(char *argv, t_flags *flags)
{
	size_t	strategies;
    //si no hay argv o no hay -- error
    if(!argv || argv[0] != '-' || argv[1] != '-')
        return(0);
    if (ft_strcmp(argv, "--simple") == 0)
        return (flags->simple = 1, 1);
    else if (ft_strcmp(argv, "--medium") == 0)
        return (flags->medium = 1, 1);
    else if (ft_strcmp(argv, "--complex") == 0)
        return (flags->complex = 1, 1);
    else if (ft_strcmp(argv, "--adaptive") == 0)
        return (flags->adaptative = 1, 1);
    else if (ft_strcmp(argv, "--bench") == 0)
        return (flags->bench = 1, 1);
    else 
        return(0);
    //strategias es la suma de las flags activadas
    strategies = flags->adaptative + flags->simple 
        + flags->medium + flags->complex;
    //si la suma es mayor que uno eso quiere decir que
    //han escrito mas de una flag en el codigo
    if(strategies > 1)
        return(0);
    flags->has_flag = strategies + flags->bench;
    if(flags->parser_nums == 0)
        flags->parser_nums = 1;
    return(1);
}
static int check_valid_num(char *argv, char **list_str, t_flags *flags)
{
    char **nums;
    int i;
    //si por aluna razon se encuentra con algo que no sea un
    //numero, devuelve error. Solo proteccion
    if(!argv || argv[0] == '-' && argv[1] == '-')
        return(0);
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
        if(!is_valid_number(nums[i++]))//pasa nums[i] a is_valid_number y luego incrementa para ñla siguiente vuelta al buble
            return(ft_free(nums), 0); //si falla libera memoria y retorna(0)
    }
    ft_free(nums); //libera todo el split(ya valido todos los textos)
    if(flags->parser_nums == 1) // si hubo algun error de logica/etc..
        return(0); //hubo error retorna 0
    if (!ft_join_args_with_space(list_str, argv))
		return (0);
    flags->parser_nums = 0; //si por el contraro no hubo error al leer nada parser sera 0
    return(1); //se ha completado con exito
}

int main(int argc, char **argv)
{
    t_flags flags;
    char **args;
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
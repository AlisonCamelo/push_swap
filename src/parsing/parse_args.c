/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 11:23:44 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/26 12:37:31 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//chequea flags e implementa las estrategias
static int process_flags(char *arg, t_flags *flags)
{
    if (ft_strcmp(arg, "--simple") == 0)//es simple??, igual simple a 1 y retorna 1
        return (flags->simple = 1, 1);
    else if (ft_strcmp(arg, "--medium") == 0)//es medium??, igual simple a 1 y retorna 1
        return (flags->medium = 1, 1);
    else if (ft_strcmp(arg, "--complex") == 0)//es complex??, igual simple a 1 y retorna 1
        return (flags->complex = 1, 1);
    else if (ft_strcmp(arg, "--adaptive") == 0)//es adaptive??, igual simple a 1 y retorna 1
        return (flags->adaptative = 1, 1);
    else if (ft_strcmp(arg, "--bench") == 0)//es bench??, igual simple a 1 y retorna 1
        return (flags->bench = 1, 1);
    else //no es ninguna
        return(0);//devuelve errorrrts
    return(1);//todo ok
}
//esta funcion verifica que si se pudo processar los numeros, es decir parsear, verificar que todo este bien, que sean validos, que no hayan duplicados, 
//y que se hayan podido asignar al stack
static int	process_nums(char *token, t_stack **stack_a)
{
	int		val;
	t_stack	*new_node;

	if (!ft_is_valid_number(token, &val))//si no son numeros validos es decir, que haya aglgo despues del numero, que no sobre pase el max y min, que sean digitos entre 0 y 9
		return (0);//adivinaaa?? return zero
	if (check_duplicates(*stack_a, val))
		return (0);
	new_node = stack_new(val);
	if (!new_node)
		return (0);
	stack_add_back(stack_a, new_node);
	return (1);
}
//esta funcion va despues de que se verifique que no hay mas flags
static int parse_str_argv(char *arg, t_stack **stack_a)
{
    char **nums;
    int i;
 
    nums = ft_split(arg, ' '); //asi que lo primero es asegurarme de separar todo lo que tenga un espacio 
    if(!nums || !*nums) // split fallo?
        return(free_split(nums), 0);//libera y retorna
    i = 0;//contadorts en 0
    while(nums[i])//mientras hayan cosas en el split separadas por coma
    {
        if(!process_nums(nums[i], stack_a))//si no se pudo procesar o convertir nums[i] en un nodo
            return(free_split(nums), 0);//libera y retorna 0
        i++;//esto debes chequearlo siempre, que si hayas podido asignarle un nodo o espacio a cada numero procesado
    }
    free_split(nums);//todo okiii?? freeeeee space
    return(1);//retorna 1, todo oki
}
//esta funcion nos permite llamar dos auxiliares, que se encargaran de procesar flags (si el usuario las escribe) y, parsear los argumentos,
//al final parse_args va a devolver un 1 si todo sale ok, el rocessamiento de flags y el parseo de los args
int parse_args(int argc, char **argv, t_stack **stack_a, t_flags *flags)
{
    int i;

    i = 1;
    while(i < argc)//mientras el contador sea menor al numero de argumentos
    {
        if(argv[i][0] == '-' && argv[i][1] == '-')//si encuentra -- en las dos primeras posiciones del argumento 
        {
            if(!process_flags(argv[i], flags))//ejecuta process_fags pero, si por alguna razon no se pudieron procesar
                return(0);//retorna 0 (problemsss)
        }
        else//si no encontro -- (quiere decir que no hay flags) por lo tanto ejecuta el parseo
        {
            if(!parse_str_argv(argv[i], stack_a))//si no se pudo ejecutar parse_str_argv
                return(0);//errorrrrr//problemssss
        }
        i++;//continua, todo esto es un chequeo por argc, hasta el final
    }
    return(1);//cuando acabes, salio todo perfecto y retorna 1
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 16:44:26 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/25 15:31:43 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');//es un numero valido?? esta entre 0 y 9???
}
//esto es como un atol pero reforzado, sirve para verificar signos si son digitos validos a demas, si no se pasan de los limites
int	ft_is_valid_number(const char *str, int *out_val)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str && (str[i] == '+' || str[i] == '-'))//si hay un signo
	{
		if (str[i] == '-')//pero si es negativo
			sign = -1;//make it positiveee
		i++;//continua nene por si hay mas 
	}
	if (!str || !str[i])//si no hy nada
		return (0);//cero, retorna cera
	while (str[i])//mientras haya algo en la posicion que se encuentra
	{
		if (!ft_is_digit(str[i]))//si no es un digito valido es decir cualquiero otra cosa rara
			return (0);//zeroooo 
		res = (res * 10) + (str[i] - '0');//esto es para poder procesar numeros largos (mas de dos digitos)
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)//si algo sobrepara el max o el min
			return (0);//retorna zeroooooooooo
		i++;
	}
	return((*out_val = (int)(res * sign)), 1);
}

int check_duplicates(t_stack *stack, int num)
{
    //mientras que stack no sea null
	
    while(stack)
    {
        if(stack->value == num)
            return(1); //Devuelve 1 cuando esta duplicado
        stack = stack->next; // continua recorriendo ("siguiente caja")
    }
    return(0);//no hay duplicados
}

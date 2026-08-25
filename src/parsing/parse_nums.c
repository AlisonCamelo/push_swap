/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 16:44:26 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/25 13:04:00 by acamelo          ###   ########.fr       */
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
	int			i, sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '+' || str[i] == '-')//si hay un signo
	{
		if (str[i] == '-')//pero si es negativo
			sign = -1;//make it positiveee
		i++;//continua nene por si hay mas 
	}
	if (!str[i])//si no hy nada
		return (0);//cero, retorna cera
	while (str[i])//mientras haya algo en la posicion que se encuentra
	{
		if (!ft_is_digit(str[i]))//si no es un digito valido
			return (0);//zeroooo 
		res = (res * 10) + (str[i] - '0');
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			return (0);
		i++;
	}
	*out_val = (int)(res * sign);
	return (1);
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

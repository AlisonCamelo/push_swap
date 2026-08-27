/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:29:34 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/26 12:48:04 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Imprime un entero en descriptor de archivo (stderr)
/*static void	ft_putnbr_fad(int n, int fd)
{
	char	c;

	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

// Imprime una cadena en descriptor de archivo (stderr)
static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
*/
// Emite el reporte de rendimiento por stderr
void	print_bench(t_flags *flags, int disorder, int total_ops, char *strategy)
{
	if (!flags->bench)
		return ;
	ft_putstr_fd("[BENCHMARK]\n", 2);
	ft_putstr_fd("Estrategia usada: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\nPorcentaje de desorden: ", 2);
	ft_putnbr_fd(disorder, 2);
	ft_putstr_fd("%\nTotal de movimientos: ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putstr_fd("\n", 2);
}
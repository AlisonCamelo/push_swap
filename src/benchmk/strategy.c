/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 18:30:19 by acamelo           #+#    #+#             */
/*   Updated: 2026/08/25 18:30:28 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	run_adaptive(t_stack **a, t_stack **b, int disorder, char **strat)
{
	if (disorder < 20)
	{
		*strat = "Simple (Adaptativo - Bajo Desorden)";
		return (sort_simple(a, b));
	}
	else if (disorder < 50)
	{
		*strat = "Medium (Adaptativo - Desorden Medio)";
		return (sort_medium(a, b));
	}
	*strat = "Complex (Adaptativo - Alto Desorden)";
	return (sort_complex(a, b));
}

int	run_strategy(t_stack **a, t_stack **b, t_flags *flags, int disorder)
{
	char	*strategy_name;
	int		ops;

	ops = 0;
	strategy_name = "Adaptativo";
	if (flags->simple)
	{
		strategy_name = "Simple";
		ops = sort_simple(a, b);
	}
	else if (flags->medium)
	{
		strategy_name = "Medium";
		ops = sort_medium(a, b);
	}
	else if (flags->complex)
	{
		strategy_name = "Complex";
		ops = sort_complex(a, b);
	}
	else
		ops = run_adaptive(a, b, disorder, &strategy_name);
	print_bench(flags, disorder, ops, strategy_name);
	return (ops);
}
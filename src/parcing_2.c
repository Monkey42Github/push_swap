/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:14:18 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/04 14:12:32 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	parce_space(char **av, char c)
{
	int	j;
	int	space;
	int	i;

	i = 1;
	while (av[i])
	{
		j = 0;
		space = 0;
		while (av[i][j])
		{
			if (av[i][j] == c)
				space++;
			j++;
		}
		if (space == j)
			quit(0);
		if (av[i][0] == '\0')
			quit(0);
		i++;
	}
}

void	plus_moin(char **av)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (av[i])
	{
		j = 0;
		sign = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
				sign++;
			j++;
		}
		i++;
		if (sign > 1)
			quit(0);
	}
}

void	plus(char **av)
{
	int	nb;
	int	sign;
	int	i;
	int	j;

	i = 0;
	sign = 0;
	while (av[i])
	{
		j = 0;
		nb = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' || av[i][j] <= '9')
				nb++;
			if ((av[i][j] == '+' || av[i][j] == '-') && nb > 1)
				quit(0);
			j++;
		}
		i++;
	}
}

void	check_double(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = 0;
		while (args[i + ++j])
			if (ft_atoi(args[i]) == ft_atoi(args[i + j]))
				quit(1);
	}
}

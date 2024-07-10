/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:59:18 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/04 15:34:48 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	sort(int **stacks)
{
	if (stacks[0][0] == 2)
		ex_two(stacks);
	else if (stacks[0][0] == 3)
		ex_three(stacks);
	else if (stacks[0][0] == 4)
		ex_four(stacks);
	else if (stacks[0][0] == 5)
		ex_five(stacks);
	else
		tri(stacks);
}

int	**ft_stack_init(int ac, char **av)
{
	int		i;
	int		**stacks;

	stacks = (int **)malloc(2 * sizeof(int *));
	stacks[0] = (int *)malloc((ac + 1) * sizeof(int));
	stacks[1] = (int *)malloc((ac + 1) * sizeof(int));
	stacks[0][0] = ac;
	stacks[1][0] = 0;
	i = 0;
	while (++i <= stacks[0][0])
		stacks[0][i] = ft_atoi(av[i - 1]);
	return (stacks);
}

int	**ft_check(int ac, char **av)
{
	char	**args;
	int		**stacks;
	int		i;

	i = 1;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		ac = 0;
		while (av[ac] != '\0')
			ac++;
	}
	while (i != ac && av[i] != '\0')
		ft_test(av[i++]);
	check_double(av);
	stacks = ft_stack_init(ac, av);
	re_compte(stacks);
	if (ft_verif(stacks) == 0)
		sort(stacks);
	i = 0;
	return (stacks);
}

int	main(int ac, char **av)
{
	int		i;
	char	*mem;
	char	**tab;
	int		**stacks;

	if (ac == 1 || av[1][0] == '\0')
		return (0);
	i = 0;
	mem = NULL;
	ft_check_space(av);
	while (av[i++])
	{
		mem = ft_strjoin(mem, av[i]);
		mem = ft_strjoin(mem, " ");
	}
	tab = ft_split(mem, ' ');
	free(mem);
	plus_moin(tab);
	plus(tab);
	i = 0;
	while (tab[i++])
		;
	stacks = ft_check(i - 1, tab);
	return (0);
}

void	ft_check_space(char **av)
{
	parce_space(av, ' ');
	parce_space(av, '-');
	parce_space(av, '+');
}

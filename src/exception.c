/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:08:00 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/04 13:28:52 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	ex_two(int **stacks)
{
	if (stacks[0][1] > stacks[0][2])
		ra(stacks);
}

void	ex_three(int **stacks)
{
	while (!ft_verif(stacks))
	{
		if (stacks[0][1] == 1)
			sa(stacks);
		if (stacks[0][1] == 2)
		{
			if (stacks[0][2] == 1)
				sa(stacks);
			else if (stacks[0][2] == 3)
				rra(stacks);
		}
		if (stacks[0][1] == 3)
		{
			if (stacks[0][2] == 1)
				ra(stacks);
			else if (stacks[0][2] == 2)
				sa(stacks);
		}
	}
}

void	ex_four(int **stacks)
{
	if (stacks[0][4] == 4)
		rra(stacks);
	else
		while (stacks[0][1] != 4)
			ra(stacks);
	pb(stacks);
	ex_three(stacks);
	pa(stacks);
	ra(stacks);
}

void	ex_five(int **stacks)
{
	int	i;

	i = 1;
	while (stacks[0][i] != 5)
		i++;
	if (i <= 3)
		while (stacks[0][1] != 5)
			ra(stacks);
	else
		while (stacks[0][1] != 5)
			rra(stacks);
	pb(stacks);
	ex_four(stacks);
	pa(stacks);
	ra(stacks);
}

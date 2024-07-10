/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:49:15 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/04 14:13:01 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	re_compte(int **stacks)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (++i <= stacks[0][0])
	{
		j = ++stacks[1][0];
		stacks[1][i] = stacks[0][i];
		while (stacks[1][j] < stacks[1][j - 1] && j > 1)
		{
			tmp = stacks[1][j - 1];
			stacks[1][j - 1] = stacks[1][j];
			stacks[1][j] = tmp;
			j--;
		}
	}
	while (--i > 0)
	{
		j = 1;
		while (stacks[0][i] != stacks[1][j])
			j++;
		stacks[0][i] = j;
	}
	stacks[1][0] = 0;
}

void	tri(int **stacks)
{
	int	size;
	int	poid;
	int	poid_max;

	poid = 1;
	poid_max = calcul_poid(stacks);
	while (poid <= poid_max)
	{
		size = stacks[0][0];
		while (size--)
		{
			if (stacks[0][1] & poid)
				ra(stacks);
			else
				pb(stacks);
		}
		while (stacks[1][0])
			pa(stacks);
		poid *= 2;
	}
}

int	calcul_poid(int **stacks)
{
	int	max;
	int	bit_weight;

	bit_weight = 1;
	max = stacks[0][0];
	while (max > 1)
	{
		max >>= 1;
		bit_weight <<= 1;
	}
	return (bit_weight);
}

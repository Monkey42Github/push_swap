/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:06:16 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/03 16:27:14 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	pa(int **stacks)
{
	int	i;

	i = ++stacks[0][0];
	while (--i)
		stacks[0][i + 1] = stacks[0][i];
	stacks[0][1] = stacks[1][1];
	i = 0;
	while (++i < stacks[1][0])
		stacks[1][i] = stacks[1][i + 1];
	stacks[1][0]--;
	write(1, "pa\n", 3);
}

void	pb(int **stacks)
{
	int	i;

	i = ++stacks[1][0];
	while (--i)
		stacks[1][i + 1] = stacks[1][i];
	stacks[1][1] = stacks[0][1];
	i = 0;
	while (++i < stacks[0][0])
		stacks[0][i] = stacks[0][i + 1];
	stacks[0][0]--;
	write(1, "pb\n", 3);
}

void	ra(int **stacks)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stacks[0][1];
	while (++i < stacks[0][0])
		stacks[0][i] = stacks[0][i + 1];
	stacks[0][i] = tmp;
	write(1, "ra\n", 3);
}

void	rra(int **stacks)
{
	int	i;
	int	tmp;

	i = stacks[0][0];
	tmp = stacks[0][i++];
	while (--i > 1)
		stacks[0][i] = stacks[0][i - 1];
	stacks[0][1] = tmp;
	write(1, "rra\n", 4);
}

void	sa(int **stacks)
{
	int	tmp;

	tmp = stacks[0][1];
	stacks[0][1] = stacks[0][2];
	stacks[0][2] = tmp;
	write(1, "sa\n", 3);
}

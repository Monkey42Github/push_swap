/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:14:18 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/04 14:12:51 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

int	ft_putnbr_fd(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			i++;
	return (i);
}

void	quit(int i)
{
	(void)i;
	write(2, "Error\n", 6);
	exit(255);
}

int	ft_atoi(const char *str)
{
	double	nbr;
	double	sign;

	nbr = 0;
	sign = 1;
	while ((*str == ' ') || (*str >= '\t' && *str <= '\r') || (*str == '0'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = 10 * nbr + (*str - '0');
		str++;
	}
	if ((nbr * sign < -2147483648 || nbr * sign > 2147483647))
		quit(1);
	return ((int)(nbr * sign));
}

int	ft_test(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	j = i;
	while (str[j] != '\0')
		j++;
	if (ft_strlen(str) >= 11 + (j - i))
		quit(1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (ft_strlen(str) != i || str[0] == '\0'
		|| (str[1] == '\0' && (str[0] == '+' || str[0] == '-')))
		quit(1);
	return (ft_atoi(str));
}

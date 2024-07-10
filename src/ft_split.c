/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:32:29 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/04 13:03:54 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

static int	count(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (i);
}

static char	*perword(char *str, int debut, int fin)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc((fin - debut + 1));
	while (debut < fin)
		word[i++] = str[debut++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (s)
		split = malloc(sizeof(char *) * (count(s, c) + 1));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while ((int)i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || (int)i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = perword(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:06:27 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/04 15:22:29 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	s1_len;
	unsigned long	s2_len;
	char			*dst;

	i = -1;
	j = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1_len && !s2_len)
		return (NULL);
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (s1_len && s1[++i])
		dst[i] = s1[i];
	while (s2_len && s2[++j])
		dst[s1_len + j] = s2[j];
	dst[s1_len + s2_len] = 0;
	if (s1)
		free(s1);
	return (dst);
}

int	ft_verif(int **tab)
{
	int	i;

	i = 0;
	while (++i < tab[0][0])
		if (tab[0][i] > tab[0][i + 1])
			return (0);
	return (1);
}

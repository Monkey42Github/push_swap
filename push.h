/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschemit <pschemit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:14:18 by pschemit          #+#    #+#             */
/*   Updated: 2022/06/04 15:32:51 by pschemit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	**ft_split(char *s, char c);
int		**ft_check(int ac, char **av);
int		ft_test(char *str);
int		ft_strlen(char *str);
void	quit(int i);
int		ft_atoi(const char *str);
void	check_double(char **args);
void	re_compte(int **stacks);

void	sa(int **stacks);
void	pa(int **stacks);
void	pb(int **stacks);
void	ra(int **stacks);
void	rra(int **stacks);

void	tri(int **stacks);
int		calcul_poid(int **stacks);

void	sort(int **stacks);
void	ex_two(int **stacks);
void	ex_three(int **stacks);
void	ex_four(int **stacks);
void	ex_five(int **stacks);
char	*ft_strjoin(char *s1, char *s2);
int		ft_verif(int **tab);
void	print_stacks(int **stacks);
void	parce_space(char **av, char c);
void	plus_moin(char **av);
void	plus(char **av);
void	ft_check_space(char **av);

#endif

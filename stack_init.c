/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:24:10 by rrisseli          #+#    #+#             */
/*   Updated: 2024/04/03 15:11:54 by rrisseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str, t_stack_node **a, char **av,
		bool flag_ac_2)
{
	int		isneg;
	int		i;

	long (num) = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
		if (i > 11)
			error_free(a, av, flag_ac_2);
	}
	return (num * isneg);
}

void	stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ac_2);
		nbr = ft_atol(av[i], a, av, flag_ac_2);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, flag_ac_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, flag_ac_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (flag_ac_2)
		free_matrix(av);
}

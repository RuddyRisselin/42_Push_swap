/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:46:13 by marvin            #+#    #+#             */
/*   Updated: 2024/03/29 12:46:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	exec_sort(char *cmd, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(cmd, "pb\n") == 0)
		pb(b, a, true);
	if (ft_strcmp(cmd, "pa\n") == 0)
		pa(a, b, true);
	if (ft_strcmp(cmd, "sa\n") == 0)
		sa(a, true);
	if (ft_strcmp(cmd, "sb\n") == 0)
		sb(b, true);
	if (ft_strcmp(cmd, "ss\n") == 0)
		ss(a, b, true);
	if (ft_strcmp(cmd, "ra\n") == 0)
		ra(a, true);
	if (ft_strcmp(cmd, "rb\n") == 0)
		rb(b, true);
	if (ft_strcmp(cmd, "rr\n") == 0)
		rr(a, b, true);
	if (ft_strcmp(cmd, "rra\n") == 0)
		rra(a, true);
	if (ft_strcmp(cmd, "rrb\n") == 0)
		rrb(a, true);
	if (ft_strcmp(cmd, "rrr\n") == 0)
		rrr(a, b, true);
	else
		return ;
}

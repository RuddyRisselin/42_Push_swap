/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:46:20 by rrisseli          #+#    #+#             */
/*   Updated: 2024/04/03 13:51:35 by rrisseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_moyenne(t_stack_node **a, int len_a)
{
	int				moyenne_a;
	int				i;
	t_stack_node	*current_value;

	i = 0;
	moyenne_a = 0;
	current_value = *a;
	while (i < len_a && current_value != NULL)
	{
		moyenne_a += current_value->value;
		current_value = current_value->next;
		i++;
	}
	moyenne_a = moyenne_a / len_a;
	return (moyenne_a);
}

void	push_in_b(t_stack_node **a, t_stack_node **b, int len_a)
{
	int				moyenne_a;
	int				i;
	t_stack_node	*current_value;

	moyenne_a = set_moyenne(a, len_a);
	current_value = *a;
	i = 0;
	while (i < stack_len(*a))
	{
		if ((*a)->value < moyenne_a)
		{
			pb(b, a, false);
			len_a--;
		}
		else
			ra(a, false);
		i++;
	}
	while (len_a-- > 3)
		pb(b, a, false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:35:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/29 12:35:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	stock_cmd(t_stack_node **a, t_stack_node **b)
{
	char	*line;

	line = get_next_line(0);
	exec_sort(line, a, b);
	free(line);
	while (line)
	{
		line = get_next_line(0);
		if (!line)
		{
			free(line);
			break ;
		}
		exec_sort(line, a, b);
		free(line);
	}
}

static int	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (ac == 2)
		av = ft_split_pushswap(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	if (is_sorted(a) == 1)
		write(1, "OK\n", 3);
	stock_cmd(&a, &b);
	if (is_sorted(a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
}

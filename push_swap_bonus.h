/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:14:07 by rrisseli          #+#    #+#             */
/*   Updated: 2024/04/03 15:21:51 by rrisseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

int		main(int ac, char **av);
void	stock_cmd(t_stack_node **a, t_stack_node **b);
void	exec_sort(char *cmd, t_stack_node **a, t_stack_node **b);

#endif
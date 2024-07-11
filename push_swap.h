/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrisseli <rrisseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:55:40 by rrisseli          #+#    #+#             */
/*   Updated: 2024/04/03 15:15:24 by rrisseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				error_syntax(char *str_nbr);
int				error_repetition(t_stack_node *a, int nbr);
char			**ft_split_pushswap(char *str, char separator);
void			error_free(t_stack_node **a, char **argv, bool flag_ac_2);
void			free_matrix(char **argv);
void			free_stack(t_stack_node **stack);

int				main(int ac, char **av);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			append_node(t_stack_node **stack, int nbr);
void			stack_init(t_stack_node **a, char **av, bool flag_ac_2);
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);

t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
void			finish_rotation(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
void			set_current_position(t_stack_node *stack);

void			push_in_b(t_stack_node **a, t_stack_node **b, int len_a);
int				set_moyenne(t_stack_node **a, int len_a);

void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			tiny_sort(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);

#endif
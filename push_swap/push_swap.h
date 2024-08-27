/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:46:05 by marigome          #+#    #+#             */
/*   Updated: 2024/08/27 13:10:35 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc, free, exit
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				data;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// CHECKERS //

int			ft_check_num(char *src);
int			ft_check_duplicates(char **args, int i, long n);
void		ft_checker_args(int argc, char **argv);
int			ft_check_len(char *src);
int			ft_is_duplicated(t_stack **a);
int			checker_sort(t_stack *a);

// ERROR //
void		ft_exit_error(t_stack **a, t_stack **b);
void		ft_free_stack(t_stack **stack);
void		free_args(char **argv);

// STACK && NODE//
t_stack		*ft_get_stack(t_stack **stack_a, char **argv, int argc);
t_stack		*ft_new_node(long int n);
void		ft_add_stack(t_stack **stack_a, t_stack *new_node);
t_stack		*stack_tail(t_stack *a);
t_stack		*stack_before_tail(t_stack *a);
int			stack_size(t_stack *a);

// FUCTIONS //
void		ft_putstr(char *src);
long int	ft_atol(char *src);

// INDEX, POSITION & TARGET //
int			ft_get_target(t_stack **a, int index_b, int limit_max, int target);
void		ft_get_target_position(t_stack **a, t_stack **b);
void		ft_get_index(t_stack *a, int stack_size);
void		ft_get_position(t_stack **a);
int			position_lowest_index(t_stack **a);

// COST //
void		ft_cost(t_stack **a, t_stack **b);
void		cheapest_move(t_stack **a, t_stack **b);

// MOVEMENTS //
// push //
void		push_a(t_stack **a, t_stack **b);
void		push_b(t_stack **a, t_stack **b);

// Reverse rotate //
void		reverse_rotate(t_stack **a);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// Rotate //
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rotate(t_stack **a);

// Swap //
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

// SORTS //
void		ft_sort_three(t_stack **a);
void		push_stack(t_stack **a, t_stack **b);
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void		sort(t_stack **a, t_stack **b);
void		sort_stack(t_stack **a);

#endif
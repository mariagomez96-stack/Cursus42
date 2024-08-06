/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:46:05 by marigome          #+#    #+#             */
/*   Updated: 2024/08/06 12:10:27 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc, free, exit
# include <unistd.h>

typedef struct s_stack
{
	int				data; //Valor
	int				index; //Índice
	int				position; //Posición actual
	int				ordered_position; //Nodo ordenado
	int				cost_a; //Coste de mov en a
	int				cost_b; //Coste de mov en b
	struct s_stack	*next; //Puntero a la propia estructura
}	t_stack; //Referencia

// CHECKERS //

int			ft_check_num(char *src);
int			ft_check_duplicates(char **args, int i, long n);
void		ft_checker_args(int argc, char **argv);
int			ft_check_len(char *src);
int			ft_is_duplicated(t_stack **a);
int			checker_sort(t_stack **a);

// ERROR //
void		ft_exit_error(t_stack **a, t_stack **b);

// STACK //
void		ft_free_stack(t_stack **stack);
t_stack		*get_min_index(t_stack **a);
t_stack		*ft_get_stack(t_stack **stack_a, char **argv, int argc);
void		get_index(t_stack **a);
t_stack		*ft_new_node(unsigned long n);
void		ft_add_stack(t_stack **stack_a, t_stack *new_node);
t_stack		*stack_tail(t_stack *a);
t_stack		*stack_before_tail(t_stack *a);
int			stack_size(t_stack **a);

// FUCTIONS //
char		**ft_split(char *str);
void		ft_putstr(char *src);
long int	ft_atol(char *src);

// MOVEMENTS //
// push //
void		push_a(t_stack **a, t_stack **b);
void		push_b(t_stack **a, t_stack **b);

// Reverse rotate //
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// Rotate //
void		rotate_a(t_stack **a);
void		rotate_b(t_stack **b);
void		rotate_both(t_stack **a, t_stack **b);

// Swap //
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
#endif
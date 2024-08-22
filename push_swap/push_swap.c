/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:44:40 by marigome          #+#    #+#             */
/*   Updated: 2024/08/22 15:11:19 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

t_stack	*ft_get_stack(t_stack **stack_a, char **argv, int argc)
{
	char			**param;
	t_stack			*node;
	int				i;
	long int		n;

	i = 0;
	if (argc == 2)
		param = ft_split(argv[1], 32);
	else
	{
		i = 1;
		param = argv;
	}
	while (param[i])
	{
		n = ft_atol(param[i]);
		node = ft_new_node(n);
		ft_add_stack(stack_a, node);
		i++;
	}
	ft_get_index(*stack_a, stack_size(*stack_a) + 1);
	if (argc == 2)
		free(param);
	return (*stack_a);
}
//Liberamos en este caso porque hemos creado memoria dinámica//

//int		i; line 58
// i = 0;  line 61

/*int	main(int ac, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		ft_checker_args(ac, argv);
		stack_a = ft_get_stack(&stack_a, argv, ac);
		if ((stack_size(&stack_a) == 2) && (!checker_sort(&stack_a)))
			sa(&stack_a);
		else if ((stack_size(&stack_a) == 3) && (!checker_sort(&stack_a)))
			ft_sort_three(&stack_a);
		else if ((stack_size(&stack_a) > 3) && (!checker_sort(&stack_a)))
			sort(&stack_a, &stack_b);
	}
	else
		ft_exit_error(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}*/

int	main(int ac, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		ft_checker_args(ac, argv);
		stack_a = ft_get_stack(&stack_a, argv, ac);
		if ((stack_size(stack_a) == 2) && (!checker_sort(stack_a)))
		{
			sa(&stack_a);
		}
		else if ((stack_size(stack_a) == 3 && (!checker_sort(stack_a))))
		{
			ft_sort_three(&stack_a);
		}
		else if ((stack_size(stack_a) > 3) && (!checker_sort(stack_a)))
		{
			sort(&stack_a, &stack_b);
		}
	}
	else
		ft_exit_error(&stack_a, &stack_b);
	
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}


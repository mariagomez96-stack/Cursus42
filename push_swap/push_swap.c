#include "push_swap.h"

int	ft_check_len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

void	ft_get_stack(t_stack **stack_a, char **argv, int argc)
{
	char	**param;
	t_stack	*node;
	int		i;
	unsigned long n;

	i = 0;
	if (argc == 2)
		param = ft_split(argv[1]);
	else
	{
		i = 1;
		param = argv;
	}
	while (param[i])
	{
		n = ft_atol(param[i]);
		node = ft_new_node(n);
		ft_add_node(stack_a, node);
		i++;
	}
	get_index(stack_a);
	if (argc == 2)
		free(argv); //Liberamos en este caso porque hemos creado memoria dinámica//
}

int	main(int ac, char **argv)
{
	int	i = 1;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		ft_exit_error(stack_a, stack_b);
	ft_checker_args(ac, argv);
	ft_get_stack(&stack_a, argv, ac);

	
}
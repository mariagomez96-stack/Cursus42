/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:41:16 by marigome          #+#    #+#             */
/*   Updated: 2024/08/06 12:51:15 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '-' || src[i] == '+')
		i++;
	while (src[i])
	{
		if (src[i] < '0' && src[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicates(char **args, int i, long n)
{
	long int	cmp;

	i++;
	cmp = 0;
	while (args[i])
	{
		cmp = ft_atol(args[i]);
		if (cmp == n)
			return (1);
		i++;
	}
	return (0);
}

void	ft_checker_args(int argc, char **argv)
{
	char			**args;
	long int		n;
	int				i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1]);
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		n = ft_atol(args[i]);
		if (!ft_check_num(argv[i]))
			ft_putstr("Error\n");
		if (ft_check_duplicates(args, i, n) == 1)
			ft_putstr("Error\n");
		if (n < -2147483648 || n > 2147483647)
			ft_putstr("Error\n");
		i++;
	}
	if (argc == 2)
		free(args);
}

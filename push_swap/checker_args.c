/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:41:16 by marigome          #+#    #+#             */
/*   Updated: 2024/08/14 10:26:55 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '\0')
		return (0);
	while (src[i])
	{
		if ((src[i] == '-' || src[i] == '+' )
			&& (src[i + 1] >= '0' && src[i + 1] <= '9'))
			i++;
		if (src[i] < 48 || src[i] > 57)
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

static void	ft_checker_basics(char **args, int i, long int n)
{
	if (ft_check_num(args[i]) == 0)
		ft_exit_error(NULL, NULL);
	if (ft_check_duplicates(args, i, n) == 1)
		ft_exit_error(NULL, NULL);
	if (n < -2147483648 || n > 2147483647)
		ft_exit_error(NULL, NULL);
}

void	ft_checker_args(int argc, char **argv)
{
	char			**args;
	long int		n;
	int				i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], 32);
	else
	{
		i = 1;
		args = argv;
	}
	if (!args || !args[i])
		ft_exit_error(NULL, NULL);
	while (args[i])
	{
		n = ft_atol(args[i]);
		ft_checker_basics(args, i, n);
		i++;
	}
	if (argc == 2)
		free(args);
}

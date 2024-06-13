/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:09:57 by marigome          #+#    #+#             */
/*   Updated: 2024/06/13 12:22:24 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_char_to_bit(const int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((c >> bit) & 1) == 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		bit--;
		usleep(100);
	}
}

static void	ft_check_pid(int pid)
{
	if (pid <= 0)
	{
		ft_printf(RED MSG_PID_2 "\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;

	i = 0;
	if (argc <= 2)
	{	
		printf(RED MSG_ARG_1"\n");
		return (1);
	}
	if (argc >= 4)
	{
		ft_printf(RED MSG_ARG_2"\n");
		return (1);
	}
	
	pid = ft_atoi(argv[1]);
	ft_check_pid(pid);
	if (argc == 3)
	{
		while (argv[2][i])
		{
			ft_char_to_bit(pid, argv[2][i]);
			i++;
		}
		ft_char_to_bit(pid, '\n');
	}
	return (0);
}

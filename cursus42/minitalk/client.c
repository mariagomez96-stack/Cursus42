/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:09:57 by marigome          #+#    #+#             */
/*   Updated: 2024/06/13 13:19:14 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void ft_char_to_bit(const int pid, char c)
{
    int             mybit;
    mybit = 7;
    while (mybit >= 0)
    {
        if (((c >> mybit) & 1) == 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        mybit--;
        usleep(200);
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

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc <= 2)
	{
		ft_printf(YELLOW MSG_ARG_1 "\n");
		return (1);
	}
	if (argc >= 4)
	{
		ft_printf(YELLOW MSG_ARG_2 "\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	ft_check_pid(pid);
	if (argc == 3)
	{
		i = 0;
		while (argv[2][i])
			ft_char_to_bit (pid, argv[2][i++]);
		ft_char_to_bit (pid, '\0');
	}
	return (0);
}

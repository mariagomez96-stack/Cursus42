/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server _bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:10:01 by marigome          #+#    #+#             */
/*   Updated: 2024/06/13 13:52:27 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_bit_to_char(int sign, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit;
	(void) context;

	c <<= 1;
	if (sign == SIGUSR1)
		c |= 1;
	bit++;
	if (bit == 8)
	{
		if ((int)c <= 126)
			ft_printf("%c", c);
		else if ((int)c >= 127)
			ft_printf("%c", c);
		bit = 0;
		c = '\0';
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_printf(RED "Signal not received, enter Cntl + C to exit");
	else
		ft_printf(GREEN "Signal received");
}

static void	ft_get_pid(void)
{
	pid_t	pid;

	pid = getpid();
	if (!pid)
		ft_printf(RED MSG_PID_2"\n");
	ft_printf(YELLOW "PID: %d\n", pid);
}

static void	ft_welcome(void)
{
	ft_printf(GREEN" _______      _______ \n");
	ft_printf(GREEN"|       \\    /       |\n");
	ft_printf(GREEN"|  W  E  L  C  O  M  E |\n");
	ft_printf(GREEN"|       /    \\       |\n");
	ft_printf(GREEN"|_______/    \\_______|\n\n");
}

static void	ft_struct(void)
{
	struct sigaction	ss;

	sigemptyset(&ss.sa_mask);
	ss.sa_sigaction = ft_bit_to_char;
	ss.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &ss, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &ss, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	ft_welcome();
	ft_get_pid();
	ft_struct();
	while (1)
	{
		sleep(300);
	}
	return (0);
}

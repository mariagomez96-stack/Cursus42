/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:58:10 by marigome          #+#    #+#             */
/*   Updated: 2024/12/10 14:11:12 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int ft_atoi(char *str)
{
    int i;
    int sign;
	int	result;

	static int calls = 0;
    calls++;
    printf("ft_atoi llamado %d veces. Cadena: %s\n", calls, str);

    if (!str || *str == '\0')
		return (0);
	i = 0;
    sign = 1;
	result = 0;
    while ((str[i] >= 9 && str[i] <= 13)
        || (str[i] == 32))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
        result = result * 10 + (str[i] - '0');
		i++;
    }
	printf("Result: %i Sign: %i\n\n", result, sign);
	return (result * sign);
}
static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_rev_str(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

unsigned int ft_count_digits(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	number;

	i = 0;
	str = malloc((ft_count_digits(n) + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	if (n < 0)
		number = -1 * n;
	else
		number = n;
	while (number != 0)
	{
		str[i++] = (number % 10) + '0';
		number /= 10;
	}
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_rev_str(str);
	return (str);
}

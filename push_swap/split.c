/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:52:40 by marigome          #+#    #+#             */
/*   Updated: 2024/08/06 12:01:22 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_wordcount(char *str)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == 32 || str[i] == 9 || str[i] == 10))
			i++;
		if (str[i])
			wordcount++;
		while (str[i] && (str[i] != 32 && str[i] != 9 && str[i] != 10))
			i++;
	}
	return (wordcount);
}

char	**ft_split(char *str)
{
	int			i;
	int			j;
	int			k;
	char		**res;

	i = 0;
	j = 0;
	k = 0;
	res = (char **)malloc(sizeof(char *) * (ft_wordcount(str) + 1));
	while (str[i])
	{
		while (str[i] && (str[i] == 32))
			i++;
		j = i;
		while (str[i] && (str[i] != 32))
			i++;
		if (i > j)
		{
			res[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(res[k++], &str[j], i - j);
		}
	}
	res[k] = '\0';
	return (res);
}

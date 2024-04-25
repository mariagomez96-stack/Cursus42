/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:46:20 by marigome          #+#    #+#             */
/*   Updated: 2024/04/25 09:04:53 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(char const *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
		else
			i++;
	}
	return (counter);
}

static void	ft_free_buffer(char **buffer, int is)
{
	while (is > 0)
	{
		is--;
		free(buffer[is]);
	}
	free (buffer);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		bi;
	char	**buffer;

	i = 0;
	bi = -1;
	buffer = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!buffer)
		return (NULL);
	while (++bi < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		buffer[bi] = ft_substr(s, i, ft_word_len(s, i, c));
		if (!buffer[bi])
		{
			ft_free_buffer(buffer, bi);
			return (0);
		}
		i += ft_word_len(s, i, c);
	}
	buffer[bi] = 0;
	return (buffer);
}

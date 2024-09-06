/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:32:24 by marigome          #+#    #+#             */
/*   Updated: 2024/05/28 11:12:21 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h> //write & read
# include <stdlib.h> //malloc

size_t	ft_strlen(char *src);

void	ft_bzero(void *ptr, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd);

#endif 

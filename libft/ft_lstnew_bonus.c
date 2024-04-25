/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:48:34 by marigome          #+#    #+#             */
/*   Updated: 2024/04/25 09:18:20 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
#include <stdio.h>
int main (void)
{
	int	*data = (int *)malloc(sizeof(int));
	*data = 42;
	t_list	*new_nodo;
	new_nodo = ft_lstnew((void *)data);
	printf("Contenido del nodo es: %d", *(int*)new_nodo->content);	
}*/

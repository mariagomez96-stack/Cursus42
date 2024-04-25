<<<<<<< HEAD
=======

>>>>>>> 9f34c9157b427d25225d3eeb36b38c6f3985cc12
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:20:24 by user              #+#    #+#             */
/*   Updated: 2024/04/25 09:24:17 by marigome         ###   ########.fr       */
=======
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-23 14:20:24 by user              #+#    #+#             */
/*   Updated: 2024-04-23 14:20:24 by user             ###   ########.fr       */
>>>>>>> 9f34c9157b427d25225d3eeb36b38c6f3985cc12
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	void	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone((*lst), del);
			*lst = tmp;
		}
	}
=======

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  tmp;

    if (lst) //Si lst no es nula
    {
        while(*lst) //Recorremos las listas de lista
        {
            tmp = (*lst)->next; //Guardamos en tmp el puntero hacia la siguiente lista
            ft_lstdelone(*lst, del); //Usamos la funcion lstdelone para eliminar esa lista
            *lst = tmp; //Le damos al puntero el valor del siguiente puntero para que se repita el ciclo
        }
    }
>>>>>>> 9f34c9157b427d25225d3eeb36b38c6f3985cc12
}

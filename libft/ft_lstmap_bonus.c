/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:36:19 by user              #+#    #+#             */
/*   Updated: 2024/04/25 09:26:59 by marigome         ###   ########.fr       */
=======
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-23 14:36:19 by user              #+#    #+#             */
/*   Updated: 2024-04-23 14:36:19 by user             ###   ########.fr       */
>>>>>>> 9f34c9157b427d25225d3eeb36b38c6f3985cc12
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		set = f(lst->content);
		node = ft_lstnew(set);
		if (!node)
		{
			del(set);
			ft_lstclear(&new, (*del));
			return (new);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
=======
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *lst_new; //Puntero a la nueva lista que creamos
    t_list  *node; //Puntero para trabajar los nodos

    if (!lst || !f)
        return (NULL);
    lst_new = NULL; //Iniciamos la nueva lista vacía
    while (lst)
    {
        node = ft_lstnew(f(lst->content)); //Aplica la funcion f al contenido 
        if (!node)                       //De la lista actual y lo guarda en el nuevo nodo
        {
            ft_lstclear(&lst_new, del); //Borra la lista creada hasta el momento
            return (NULL);
        }
        ft_lstadd_back(&lst_new, node); //Agrega el nuevo nodo a la lista nueva
        lst = lst->next; //Avanza al siguiente nodo de la lista actual
    }
    return (new);
}
>>>>>>> 9f34c9157b427d25225d3eeb36b38c6f3985cc12

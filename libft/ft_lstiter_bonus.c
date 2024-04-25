/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:30:10 by user              #+#    #+#             */
/*   Updated: 2024/04/25 08:49:50 by marigome         ###   ########.fr       */
=======
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-23 14:30:10 by user              #+#    #+#             */
/*   Updated: 2024-04-23 14:30:10 by user             ###   ########.fr       */
>>>>>>> 9f34c9157b427d25225d3eeb36b38c6f3985cc12
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f (lst->content);
		lst = lst->next;
	}
}
=======
void    ft_lstiter(t_list *lst, void (*f)(void))
{
    if (!lst || !f)
        return ;
    while(lst) //Recorremos lst
    {
        f(lst->content); //Le aplicamos la funcion a lst->content
        lst = lst->next; //Le damos a lst el valor de lst->next
    }
}
>>>>>>> 9f34c9157b427d25225d3eeb36b38c6f3985cc12

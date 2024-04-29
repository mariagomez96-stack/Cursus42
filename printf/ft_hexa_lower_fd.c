/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_lower_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:09:39 by marigome          #+#    #+#             */
/*   Updated: 2024/04/29 13:27:04 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_hexa_lower(int c, int counter)
{
	if (c >= 16)
	{
		ft_hexa_lower_fd(c / 16);
		ft_hexa_lower_fd(c % 16);		
	}
	else
	{
		if (c)
	}
	
}
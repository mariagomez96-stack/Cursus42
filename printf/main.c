/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:43:51 by marigome          #+#    #+#             */
/*   Updated: 2024/05/02 13:11:48 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	var1;
	int	var2;
	char *s = "Luego vamos a por una cerveza, no?";
	
	var1 = ft_printf("%d", -10);
	printf("\nCaractyeres anterior -> %d\n", var1);
	var1 = ft_printf("Me ----> p:  %p  \n", s);
	var1 = ft_printf("Me ----> x:  %x  \n", 12345);
	var2 = printf("Me ----> s:  %s, d: %d \n", "toto", 423);
	printf("Me -> %d\n", var1);
	printf("Oficial -> %d\n", var2);
	return (0);
}

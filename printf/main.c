/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:43:51 by marigome          #+#    #+#             */
/*   Updated: 2024/05/03 12:34:02 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int				var1;
	int				var2;
	int				var3;
	int				var4;
	int				var5;
	char			*ptr;

	ptr = "12345678";
	printf("------- FT_PRINTF PROOFS -------\n");
	var1 = ft_printf("Hola %s, el último carácter del abecedario es la %c y el primero la %c\n", "mundo", 'z', 'A');
	ft_printf("El número de carácteres es: %d\n", var1);
	ft_printf("\n");
	var2 = ft_printf("Prueba de dígito: %d, dígito negativo: %d, dígito nulo: %d\n", 42, -2, 0, 2147483647);
	ft_printf("El número de carácteres es: %d\n", var2);
	ft_printf("\n");
	var3 = ft_printf("Prueba de dígito sin signo: %u, con negativo: %u, unsigned min: %u, unsigned max: %u\n", 42, -56, 0, 2147483647);
	ft_printf("El número de carácteres es: %d\n", var3);
	ft_printf("\n");
	var4 = printf("Prueba de hexadecimales min: %x, HEX_max: %x\n", 0, 2147483647);
	ft_printf("El número de carácteres es: %d\n", var4);
	ft_printf("\n");
	var5 = ft_printf("Prueba de puntero: %p\n", &ptr);
	ft_printf("El número de carácteres es: %d\n", var5);
	ft_printf("\n");
	printf("------- PRINTF ORIGINAL PROOFS -------\n");
	var1 = ft_printf("Hola %s, el último carácter del abecedario es la %c y el primero la %c\n", "mundo", 'z', 'A');
	printf("El número de carácteres es: %d\n", var1);
	printf("\n");
	var2 = ft_printf("Prueba de dígito: %d, dígito negativo: %d, dígito nulo: %d\n", 42, -2, 0, 2147483647);
	printf("El número de carácteres es: %d\n", var2);
	printf("\n");
	var3 = ft_printf("Prueba de dígito sin signo: %u, con negativo: %u, unsigned min: %u, unsigned max: %u\n", 42, -56, 0, 2147483647);
	printf("El número de carácteres es: %d\n", var3);
	printf("\n");
	var4 = printf("Prueba de hexadecimales min: %x, HEX_max: %x\n", 0, 2147483647);
	printf("El número de carácteres es: %d\n", var4);
	ft_printf("\n");
	var5 = ft_printf("Prueba de puntero: %p\n", &ptr);
	printf("El número de carácteres es: %d\n", var5);
	printf("\n");
	return (0);
}

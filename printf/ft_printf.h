/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:39:05 by marigome          #+#    #+#             */
/*   Updated: 2024/04/29 13:05:06 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/// @brief Mi función principal que me muestra en pantalla
/// argumentos, según una serie de casos.
/// @param str Es mi variable fija
/// @param ... Son mis variables variadicas
/// @return counter (Longitud de string que muestra)
int		ft_printf(char const *str, ...);

/// @brief  Con esta función %c me imprime un carácter
/// @param c El carácter que le paso con *str
/// @param counter El contador que necesito para mi return en printf
int	ft_putchar_fd(char c);

/// @brief Con esta funcion %f e %i, me escribe un entero
int	ft_putnbr_fd(int c, int counter);

/// @brief Con esta función, si %s, me escribe todos los carácteres de un string
int	ft_putstr_fd(char *str);

/// @brief %u -> Convertimos un entero en un numero sin signo
int	ft_putint_fd(int c, int counter);


#endif
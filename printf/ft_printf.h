/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:39:05 by marigome          #+#    #+#             */
/*   Updated: 2024/04/26 11:46:34 by marigome         ###   ########.fr       */
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
void	ft_putchar_fd(char c, size_t *counter);

#endif
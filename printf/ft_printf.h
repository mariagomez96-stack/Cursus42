/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:50:40 by marigome          #+#    #+#             */
/*   Updated: 2024/05/03 12:08:41 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/// @brief Retorna 1 y escribe el carácter
/// @param c Carácter a escribir y contabilizar
/// @return 1 (len)
int	ft_found_c(int c);

/// @brief Si s existe, escribe el string y contabiliza sus carácteres
/// @param s string
/// @param counter Utilizamos el contador que 
/// hemos estado usando en el resto de printf 
/// Le seguimos sumando los carácteres de s
/// @return counter
int	ft_found_s(char *s, int counter);

/// @brief Escribe un entero como carácter (Tiene en cuenta el mín int)
/// @param c Número a escribir
/// @return Retorna la longitud del número que vamos a escribir
/// (Hacemos un numlen)
int	ft_found_d(int c);

/// @brief Esta función tiene en cuenta si el prefijo está en
/// mayus (X) o min (x) y en base a eso, utilizamos la recursividad
/// mientras que nb sea >= 16 sumando contador para ver la longitud
/// Una vez esta condición no se da, ft_found_c("0123456789ABCDEF"[nb % 16])
/// @param nb numero unsigned long long
/// @param c type 'X' | type 'x' (Con s[i])
/// @return i
int	ft_found_hex(unsigned long long nb, char c);

/// @brief Devuelve un entero sin signo (Tiene en cuenta su máximo)
/// @param n  Número entero que imprime
/// @return El tamaño del número. Hacemnos una función de numlen_unsigned
int	ft_found_u(unsigned int n);

/// @brief Escribe la dirección de memoria de una variable 
///(uintptr_t y f_hexadecimal) 
/// @param ptr puntero
/// @return la longitud de cadenas
int	ft_found_p(uintptr_t ptr);

/// @brief Réplica de printf oficial. Te devuelve el contador 
/// de la longitud de string y tiene en cuenta
/// Las variables variadicas en dicho contador
/// @param s string que recorremos. Si encuentra un % tiene que:
/// aplicar al argumento alguna función
/// @param  va_list (args), va_start (args, s), va_arg(args, tipo de dato) 
/// Cuando aplica algo a los argumentos
/// va_end(args) cuando dejamos de tenerlos en cuenta al final de la función
/// @return contador
int	ft_printf(const char *s, ...);

#endif
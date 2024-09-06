/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:35:28 by marigome          #+#    #+#             */
/*   Updated: 2024/09/06 15:43:14 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_error(int argc, char **argv, t_fdf *fdf)
{
    if (argc != 2)
        ft_printf("The number of args is wrong!");
}
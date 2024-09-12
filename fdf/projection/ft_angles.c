/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:35:26 by marigome          #+#    #+#             */
/*   Updated: 2024/09/12 15:07:39 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double  ft_reset_ang(double *angle)
{
    double  pi2;

    pi2 = 2.00 * M_PI;
    while (*angle >= pi2)
        *angle -= pi2;
    while (*angle < 0)
        *angle += pi2;
    return (*angle);
}

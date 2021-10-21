/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 02:34:45 by skelly            #+#    #+#             */
/*   Updated: 2021/10/22 02:35:43 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_fractol(t_fractol *fractol)
{
	fractol->color++;
	if (fractol->color > 4)
		fractol->color = 1;
}

int key_control(int key, t_fractol *fractol)
{
	if (key == CLOSE_ESC)
		exit(0);
	if (key == COLOR_C)
		color_fractol(fractol);
	draw_fractol(fractol);
	return (0);
}
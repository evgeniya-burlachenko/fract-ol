/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:35:31 by skelly            #+#    #+#             */
/*   Updated: 2021/11/02 16:51:34 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	fractol_zoom(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int	mouse_control(int key, int x, int y, t_fractol *fractol)
{	
	t_complex	mouse;
	double		zoom;
	//printf("%i\n", key);
	if (key == MOUSE_BUTTON)
		fractol->press = !fractol->press;
	mouse.re = (fractol->min.re + x
			* ((fractol->max.re - fractol->min.re) / (WIDTH)));
	mouse.im = (fractol->max.im - y
			* ((fractol->max.im - fractol->min.im) / (HEIGHT)));
	if (key == MOUSE_ZOOM_PLUS)
		zoom = 1.20;
	else if (key == MOUSE_ZOOM_MINUS)
		zoom = 0.80;
	else
		zoom = 1.0;
	fractol->min.re = fractol_zoom(mouse.re, fractol->min.re, zoom);
	fractol->min.im = fractol_zoom(mouse.im, fractol->min.im, zoom);
	fractol->max.re = fractol_zoom(mouse.re, fractol->max.re, zoom);
	fractol->max.im = fractol_zoom(mouse.im, fractol->max.im, zoom);
	draw_fractol(fractol);
	return (0);
}

int	change_julia(int x, int y, t_fractol *fractol)
{
	if (fractol->press == 1)
	{
		fractol->k = init_complex(
				4 * ((double)x / WIDTH - 0.5),
				4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractol(fractol);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 02:34:45 by skelly            #+#    #+#             */
/*   Updated: 2021/11/02 16:48:38 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	moving(int key, t_fractol *fractol)
{
	t_complex	delta;

	delta = init_complex((fractol->max.re - fractol->min.re) * 0.05,
			(fractol->max.im - fractol->min.im) * 0.05);
	if (key == ARROW_LEFT)
	{
		fractol->min.re = fractol->min.re - delta.re;
		fractol->max.re = fractol->max.re - delta.re;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->min.re = fractol->min.re + delta.re;
		fractol->max.re = fractol->max.re + delta.re;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->min.im = fractol->min.im - delta.im;
		fractol->max.im = fractol->max.im - delta.im;
	}
	else if (key == ARROW_UP)
	{
		fractol->min.im = fractol->min.im + delta.im;
		fractol->max.im = fractol->max.im + delta.im;
	}
}

void	color_fractol(t_fractol *fractol)
{
	fractol->color++;
	if (fractol->color > 3)
		fractol->color = 1;
}

int	key_control(int key, t_fractol *fractol)
{
	printf("%i\n", key);
	if (key == PLUS_NUM_LOCK || key == PLUS)
	{
		if (fractol->max_iter < 50)
			fractol->max_iter += 1;
		else if (fractol->max_iter < 1000000000)
			fractol->max_iter *= 1.05;
	}
	if (key == MINUS_NUM_LOCK || key == MINUS)
	{
		if (fractol->max_iter > 50)
			fractol->max_iter *= 0.95;
		else if (fractol->max_iter > 1)
			fractol->max_iter -= 1;
	}
	if (key == RESET_R)
		init_default(fractol);
	if (key == CLOSE_ESC)
		exit(0);
	if (key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_DOWN || key == ARROW_UP)
		moving(key, fractol);
	if (key == COLOR_C)
		color_fractol(fractol);
	draw_fractol(fractol);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 02:01:40 by skelly            #+#    #+#             */
/*   Updated: 2021/11/02 16:47:00 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;
	//Чтобы покрасить x пиксель в y строке, 
	// надо найти какой у него индекс в массиве addr
	dst = fractol->image->addr + (y * fractol->image->line_len
			+ x * (fractol->image->bpp / 8));
	//y * длину строки + x * 4 - потому что rgba
	*(unsigned int *)dst = color;
}

int	init_color(t_fractol *fractol)
{
	double	t;
	int		color[4];
	//деления количества итераций, соответствующих конкретному
	//пикселю, на максимальное количество итераций,
	//это дает нам число t на единичном интервале
	t = (double)fractol->iter / (double)fractol->max_iter;
	color[0] = 0;
	if (fractol->color == 1)
	{
		//полиномы Бернштейна
		color[1] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[2] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	if (fractol->color == 2)
	{
		color[2] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[1] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[3] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	if (fractol->color == 3)
	{
		color[3] = (int)(9 * (1 - t) * pow(t, 3) * 255);
		color[1] = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
		color[2] = (int)(8.5 * pow((1 - t), 3) * t * 255);
	}
	return (create_trgb(color[0], color[1], color[2], color[3]));
}

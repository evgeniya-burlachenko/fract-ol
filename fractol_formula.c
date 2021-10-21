/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_formula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 02:13:30 by skelly            #+#    #+#             */
/*   Updated: 2021/10/22 02:14:31 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *fractol)
{
	t_complex	z;

	z = init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 
			&& fractol->iter < fractol->max_iter)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractol->c.re, 2.0 * z.re * z.im + fractol->c.im);
		fractol->iter++;
	}
}
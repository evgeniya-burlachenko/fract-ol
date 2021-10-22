/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_formula.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 02:13:30 by skelly            #+#    #+#             */
/*   Updated: 2021/10/22 18:47:28 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Z_(n) = Z²_(n-1) + c, where, Z_(0) = c
//(pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 - формула круга
//с это комплексное число, которое мы проверяем, 
//мы его получили из перевода координаты пикселя 
//на комплексную плоскость
//Потом просто записываем это полученное число в структуру z
//И начинаем проверять z, 
//насколько быстро оно вылетает из круга радиусом 2
//Мы умножаем z само на себя
//В зависимости от количества итераций, 
//закрашиваем пиксель нужным цветом
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

void	julia(t_fractol *fractol)
{
	t_complex	z;

	z = init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& fractol->iter <  fractol->max_iter)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractol->k.re, 2.0 * z.re * z.im + fractol->k.im);
		fractol->iter++;	
	}
}

void	burning_ship(t_fractol *fractol)
{
	t_complex	z;

	z = init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4 && fractol->iter < fractol->max_iter)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
				+ fractol->c.re, -2.0 * fabs(z.re * z.im) + fractol->c.im);
		fractol->iter++;
	}
}
void		celtic_mandelbar(t_fractol *fractol)
{
	t_complex	z;

	z = init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& fractol->iter < fractol->max_iter)
	{
		z = init_complex(
			fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + fractol->c.re,
			-2.0 * z.re * z.im + fractol->c.im);
		fractol->iter++;
	}
}

void		perpendicular_buffalo(t_fractol *fractol)
{
	t_complex	z;

	z = init_complex(fractol->c.re, fractol->c.im);
	fractol->iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& fractol->iter < fractol->max_iter)
	{
		z = init_complex(
			fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + fractol->c.re,
			-2.0 * z.re * fabs(z.im) + fractol->c.im);
		fractol->iter++;
	}

}

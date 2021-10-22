/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:33:36 by skelly            #+#    #+#             */
/*   Updated: 2021/10/22 19:32:54 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	*image_init(t_fractol *fractol)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if(!image)
		return(0);
	//Теперь мы можем инициализировать изображение
	//размером 1000 × 1000 следующим образом:
	image->img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	//чтобы записать в изображение пиксели нужно получить 
	//адрес памяти, по которому мы изменим байты. 
	//Мы получаем этот адрес следующим образом:
	image->addr = mlx_get_data_addr(image->img,
			&(image->bpp), &(image->line_len),
			&(image->endian));
	return (image);
}
//Теперь у нас есть адрес изображения, но все еще нет пикселей. 
//но line_length длина строки не всегда равна ширине окна .
//Поэтому мы должны ВСЕГДА вычислять смещение памяти
//используя формулу:
//int offset = (y * line_length + x * (bpp / 8)); -> draw_fractol

t_complex	init_complex(double re, double im)// инициализация комплексного числа
{
	t_complex	complex;
	
	complex.re = re;
	complex.im = im;
	return (complex);
}

void	init_default(t_fractol *fractol)
{
	fractol->max_iter = 50;//Чем больше будет указанное число, тем точнее будет полученное изображение фрактала. И тем больше вычислительных задач ляжет на компьютер.
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im + (fractol->max.re 
			- fractol->min.re) * HEIGHT / WIDTH; 
	fractol->color = 1;
	fractol->press = 0;
	fractol->k = init_complex(-0.4, 0.6);
}
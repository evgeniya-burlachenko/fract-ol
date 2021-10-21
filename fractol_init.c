/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:33:36 by skelly            #+#    #+#             */
/*   Updated: 2021/10/21 13:52:46 by skelly           ###   ########.fr       */
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
	//размером 1000 × 1080 следующим образом:
	image->img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	//чтобы записать в изображение пиксили нужно получить 
	//адрес памяти, по которому мы изменим байты. 
	//Мы получаем этот адрес следующим образом:
	image->addr = mlx_get_data_addr(image->img,
			&(image->bpp), &(image->line_length),
			&(image->endian));
	return (image);
}
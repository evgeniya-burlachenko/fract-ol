/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:03:38 by skelly            #+#    #+#             */
/*   Updated: 2021/10/21 13:32:49 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL.H
# define FRACTOL_H

# define WIDTH 			1000
# define HEIGHT			1000

#include "./libft/libft.h"

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_fractol
{
	t_image		 *image;
	void		*mlx_ptr;
	void		*window_ptr;
	
}t_fractol;

#endif
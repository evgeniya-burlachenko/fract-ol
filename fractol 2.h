/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:26:19 by ebhakaz           #+#    #+#             */
/*   Updated: 2021/10/16 16:12:48 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 1000
# define WIDTH 1000

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./minilibx/mlx.h"
# include <math.h>

# define MOUSE_SCROLL_UP	4
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define ARROW_DOWN			125
# define ARROW_UP			126
# define MAIN_PAD_ESC		53

//5 % -53 
//backspace	8	
typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_image
{
	void		*image;
	char		*data_addr;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
}				t_image;

typedef struct s_fractol
{
	t_image		*image;
	void		*mlx_ptr;
	void		*win_ptr;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	t_complex	k;
	int			iter;
	int			max_iter;
	int			press;
	int			shift;
	void		(*formula)(struct s_fractol *);
}				t_fractol;

t_complex	init_complex(double re, double im);
t_image		*init_image(t_fractol *fractol);
void		init_default(t_fractol *fractol);
int			init_color(t_fractol *fractol);
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
double		interpolate(double start, double end, double interpolation);
int			mouse_control(int key, int x, int y, t_fractol *fractol);
int			key_control(int key, t_fractol *fractol);
void		draw_fractal(t_fractol *fractol);
void		mandelbrot(t_fractol *fractol);
void		julia(t_fractol *fractol);
void		start(t_fractol *fractol);
void		parse_arg(char *arg);
void		print_help(void);
int			change_julia(int x, int y, t_fractol *fractol);
void		moving(int key, t_fractol *fractol);
void		color_shift(t_fractol *fractol);
void		burning_ship(t_fractol *fractol);

#endif
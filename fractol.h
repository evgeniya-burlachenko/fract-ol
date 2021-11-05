/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:03:38 by skelly            #+#    #+#             */
/*   Updated: 2021/11/02 17:36:50 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 				1000
# define HEIGHT				1000


# define KEY_PRESS			2
# define MOUSE_PRESS		4
# define MOUSE_MOTION		6

# define MOUSE_ZOOM_PLUS	5
# define MOUSE_ZOOM_MINUS	4
# define MOUSE_BUTTON		1

# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define ARROW_DOWN			125
# define ARROW_UP			126

# define PLUS_NUM_LOCK		69
# define PLUS				24
# define MINUS_NUM_LOCK		78
# define MINUS				27

# define RESET_R			15
# define COLOR_C			8
# define CLOSE_ESC			53

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <stdio.h>
# include <math.h>
//инициализация комплексного числа
typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;
//структура для буферизации изображения
typedef struct s_image
{
	void		*img;//экземпляр изображения
	char		*addr;//адрес памяти изображения - массив битов
	int			bpp;//32 бита
	int			line_len;//кол-во битов для строки
	int			endian;
}				t_image;

typedef struct s_fractol
{
	void		(*formula)(struct s_fractol *);
	t_image		*image;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	t_complex	k;
	void		*mlx_ptr;
	void		*window_ptr;
	int			iter;
	int			max_iter;
	int			color;
	int			press;
}t_fractol;

//fractol_init.c
t_image		*image_init(t_fractol *fractol);
t_complex	init_complex(double re, double im);
void		init_default(t_fractol *fractol);
//fractol_color.c
int			create_trgb(int t, int r, int g, int b);
void		my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
int			init_color(t_fractol *fractol);
//fractol.c
void		draw_fractol(t_fractol *fractol);
void		start_fractol(t_fractol *fractol);
void		parse_fractol(char *argv, t_fractol *fractol);
void		menu_fractol(void);
//fractol_formula.c
void		mandelbrot(t_fractol *fractol);
void		julia(t_fractol *fractol);
void		burning_ship(t_fractol *fractol);
void		celtic_mandelbar(t_fractol *fractol);
void		perpendicular_buffalo(t_fractol *fractol);
//fractol_key.c
void		color_fractol(t_fractol *fractol);
int			key_control(int key, t_fractol *fractol);
void		moving(int key, t_fractol *fractol);
//fractol_mouse.c
double		fractol_zoom(double start, double end, double zoom);
int			mouse_control(int key, int x, int y, t_fractol *fractol);
int			change_julia(int x, int y, t_fractol *fractol);
#endif
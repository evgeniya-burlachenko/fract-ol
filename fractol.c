/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:03:28 by skelly            #+#    #+#             */
/*   Updated: 2021/11/01 14:16:02 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_fractol(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	factor;
	//factor показывает чему равен пиксель на комплексной плоскости
	//ширина комплексной плоскости / ширина экрана
	//высота комплексной плоскости / высота экрана
	factor = init_complex((fractol->max.re - fractol->min.re) / (WIDTH ),
			(fractol->max.im - fractol->min.im) / (HEIGHT ));
	y = 0;
	while (y < HEIGHT)
	{
		//c.im считается особым образом. 
		//Это происходит по причине того, 
		//что ось y в окне программы направлена сверху вниз, 
		//а не снизу вверх как мы привыкли.
		fractol->c.im = fractol->max.im - y * factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * factor.re;
			fractol->formula(fractol);
			//если не попадает в множество мандельброта
			my_mlx_pixel_put(fractol, x, y, init_color(fractol));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->window_ptr,
		fractol->image->img, 0, 0);
}

void	start_fractol(t_fractol *fractol)
{
	//мы должны выполнить mlx_init функцию. 
	//Это установит соединение с правильной графической системой
	//и вернет, void *который содержит местоположение
	//нашего текущего экземпляра MLX. 
	fractol->mlx_ptr = mlx_init();
	//функция, которая вернет указатель на только что созданное окно.
	//Мы можем указать высоту, ширину и заголовок окна. 
	fractol->window_ptr = mlx_new_window(fractol->mlx_ptr,
			WIDTH, HEIGHT, "Fract-ol");
	//теперь обработаю изображение в отдельной ф-ции
	fractol->image = image_init(fractol);
	//Теперь у нас есть адрес изображения, но все еще нет пикселей. 
	//но line_length длина строки не всегда равна ширине окна .
	//Поэтому мы должны ВСЕГДА вычислять смещение памяти
	//используя формулу:
	//int offset = (y * line_length + x * (bpp / 8)); -> draw_fractol
	init_default(fractol);
	mlx_hook(fractol->window_ptr, KEY_PRESS, 0, key_control, fractol);
	mlx_hook(fractol->window_ptr, MOUSE_PRESS, 0, mouse_control, fractol);
	if (fractol->formula == &julia)
		mlx_hook(fractol->window_ptr, MOUSE_MOTION, 0, change_julia, fractol);
	draw_fractol(fractol);
	
	// нужно будет вызвать, mlx_loop, чтобы начать рендеринг окна. 
	mlx_loop(fractol->mlx_ptr);
}

void	parse_fractol(char *argv)
{
	t_fractol	*fractol;
	
	fractol = malloc(sizeof(t_fractol));
	if (!(ft_strncmp(argv, "Mandelbrot", 11)))
	{
		fractol->formula = &mandelbrot;
		start_fractol(fractol);
	}
	else if (!(ft_strncmp(argv, "Julia", 6)))
	{
		fractol->formula = &julia;
		start_fractol(fractol);
	}
	else if (!(ft_strncmp(argv, "Burning_Ship", 13)))
	{
		fractol->formula = &burning_ship;
		start_fractol(fractol);
	}
	else if (!(ft_strncmp(argv, "Celtic_mandelbar", 16)))
	{
		fractol->formula = &celtic_mandelbar;
		start_fractol(fractol);
	}
	else if (!(ft_strncmp(argv, "Perpendicular_buffalo", 22)))
	{
		fractol->formula = &perpendicular_buffalo;
		start_fractol(fractol);
	}
	
	free(fractol);
	menu_fractol();
}

void	menu_fractol(void)
{
	printf(" ------------------------------------------------------------------------ \n");
	printf("| Commands:                                                              |\n");
	printf("| Draw a Mandelbrot set                 ./fractol Mandelbrot             |\n");
	printf("| Draw a Julia set                      ./fractol Julia                  |\n");
	printf("| Draw a Burning_Ship set               ./fractol Burning_Ship           |\n");
	printf("| Draw a Celtic_mandelbar set           ./fractol Celtic_mandelbar       |\n");
	printf("| Draw a Perpendicular_buffalo set      ./fractol Perpendicular_buffalo  |\n");
	printf("|                                                                        |\n");
	printf("| Control:                                                               |\n");
	printf("| Zoom                    scroll                                         |\n");
	printf("| Moving                  arrows                                         |\n");
	printf("| Switch color scheme     c                                              |\n");
	printf("| Basic set               r                                              |\n");
	printf("| For Julia set:                                                         |\n");
	printf("| Change a parameter      mouse button and move mouse                    |\n");
	printf(" ------------------------------------------------------------------------ \n");
	exit(0);
}

int main (int argc, char **argv)
{
	if (argc == 2)
		parse_fractol(argv[1]);
	else
		menu_fractol();
	return (0);
}
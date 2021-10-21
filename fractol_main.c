/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skelly <skelly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:03:28 by skelly            #+#    #+#             */
/*   Updated: 2021/10/21 13:31:37 by skelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	// нужно будет вызвать, mlx_loop, чтобы начать рендеринг окна. 
	mlx_loop(fractol->mlx_ptr);
}

void	parse_fractol(char *argv)
{
	t_fractol	*fractol;
	
	fractol = malloc(sizeof(t_fractol));
	if (!(ft_strncmp(argv, "Mandelbrot", 11)))
	{
		start_fractol(fractol);
	}
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
	printf("| Change a parameter      press and hold the left                        |\n");
	printf("|                         mouse button and move mouse                    |\n");
	printf(" ------------------------------------------------------------------------ \n");
	exit(0);
}

int main (int argc, char **argv)
{
	if (argc == 2)
		parse_fracto(argv[1]);
	else
		menu_fractol();
	return (0);
}
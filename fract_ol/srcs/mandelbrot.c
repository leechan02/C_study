/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:20:25 by euiclee           #+#    #+#             */
/*   Updated: 2022/11/14 09:34:32 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandel_key(int keycode, t_data *data)
{
	hook_keycode(keycode, data);
	mlx_clear_window(data->mlx, data->win);
	make_mandel(data);
	return (0);
}

int	mandel_mouse(int keycode, int x, int y, t_data *data)
{
	hook_mouse(keycode, x, y, data);
	mlx_clear_window(data->mlx, data->win);
	mouse_zoom(data);
	make_mandel(data);
	return (0);
}

void	init_mandel(t_data *data)
{
	int		n;
	double	a;
	double	b;
	double	tmp;

	a = (data->x * ((data->map_right - data->map_left) / (double)WIN_X)
			+ data->map_left) + data->mv_x;
	b = (data->y * ((data->map_bottom - data->map_top) / (double)WIN_Y)
			+ data->map_top) + data->mv_y;
	data->real = 0;
	data->imag = 0;
	n = 0;
	while (n < N_MAX && data->real * data->real + data->imag * data->imag < 4)
	{
		tmp = data->real;
		data->real = data->real * data->real - data->imag * data->imag + a;
		data->imag = 2 * data->imag * tmp + b;
		n++;
	}
	my_mlx_pixel_put(data, data->x, data->y, color(n, data));
}

void	make_mandel(t_data *data)
{
	data->x = 0;
	while (data->x < WIN_X)
	{
		data->y = 0;
		while (data->y < WIN_Y)
		{
			init_mandel(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	mandelbrot(void)
{
	t_data	data;

	data.zoom = 1;
	data.mv_x = 0;
	data.mv_y = 0;
	data.map_left = -2;
	data.map_top = 2;
	data.map_right = 2;
	data.map_bottom = -2;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_X, WIN_Y, "fractol");
	data.img = mlx_new_image(data.mlx, WIN_X, WIN_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	make_mandel(&data);
	mlx_hook(data.win, KEY_PRESS, 0, mandel_key, &data);
	mlx_hook(data.win, MOUSE_PRESS, 0, mandel_mouse, &data);
	mlx_hook(data.win, X_BUTTON, 0, close_window, &data);
	mlx_loop(data.mlx);
}

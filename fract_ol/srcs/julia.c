/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:59:45 by euiclee           #+#    #+#             */
/*   Updated: 2022/11/07 12:53:57 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_key(int keycode, t_data *data)
{
	hook_keycode(keycode, data);
	mlx_clear_window(data->mlx, data->win);
	make_julia(data);
	return (0);
}

int	julia_mouse(int keycode, int x, int y, t_data *data)
{
	hook_mouse(keycode, x, y, data);
	mouse_zoom(data);
	mlx_clear_window(data->mlx, data->win);
	make_julia(data);
	return (0);
}

void	init_julia(t_data *data, double x, double y)
{
	int		n;
	double	tmp;

	if (data->param == 0)
	{
		x = data->mouse_x / ((double)WIN_X / 4) - 2;
		y = data->mouse_y / ((double)WIN_Y / -4) + 2;
	}
	data->real = (data->x * ((data->map_right - data->map_left) / (double)WIN_X)
			+ data->map_left) + data->mv_x;
	data->imag = (data->y * ((data->map_bottom - data->map_top) / (double)WIN_Y)
			+ data->map_top) + data->mv_y;
	n = 0;
	while (n < N_MAX && data->real * data->real + data->imag * data->imag < 4)
	{
		tmp = data->real;
		data->real = data->real * data->real - data->imag * data->imag + x;
		data->imag = 2 * data->imag * tmp + y;
		n++;
	}
	my_mlx_pixel_put(data, data->x, data->y, color(n, data));
}

void	make_julia(t_data *data)
{
	double	x;
	double	y;

	x = data->julia_x;
	y = data->julia_y;
	data->x = 0;
	while (data->x < WIN_X)
	{
		data->y = 0;
		while (data->y < WIN_Y)
		{
			init_julia(data, x, y);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	julia(int ac, char **av)
{
	t_data	data;

	param_check(ac, av, &data);
	data.zoom = 1;
	data.mv_x = 0;
	data.mv_y = 0;
	data.mouse_x = WIN_X / 2;
	data.mouse_y = WIN_Y / 2;
	data.map_left = -2;
	data.map_top = 2;
	data.map_right = 2;
	data.map_bottom = -2;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_X, WIN_Y, "fractol");
	data.img = mlx_new_image(data.mlx, WIN_X, WIN_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	make_julia(&data);
	mlx_hook(data.win, KEY_PRESS, 0, julia_key, &data);
	mlx_hook(data.win, MOUSE_PRESS, 0, julia_mouse, &data);
	mlx_hook(data.win, X_BUTTON, 0, close_window, &data);
	mlx_loop(data.mlx);
}

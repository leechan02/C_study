/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:20:38 by euiclee           #+#    #+#             */
/*   Updated: 2022/11/07 13:25:59 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	hook_mouse(int keycode, int x, int y, t_data *data)
{
	if (keycode == 5)
		data->zoom *= 0.9;
	else if (keycode == 4)
		data->zoom *= 1.1;
	data->mouse_x = x;
	data->mouse_y = y;
}

void	hook_keycode(int keycode, t_data *data)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 18)
		data->color = 1;
	if (keycode == 19)
		data->color = 2;
	if (keycode == 20)
		data->color = 3;
	if (keycode == 21)
		data->color = 4;
	if (keycode == 126)
		data->mv_y += 0.1 * data->zoom;
	if (keycode == 125)
		data->mv_y -= 0.1 * data->zoom;
	if (keycode == 124)
		data->mv_x += 0.1 * data->zoom;
	if (keycode == 123)
		data->mv_x -= 0.1 * data->zoom;
}

void	param_check(int ac, char **av, t_data *data)
{
	if (ac == 2)
		data->param = 0;
	else
	{
		data->param = 1;
		data->julia_x = ft_atod(av[2]);
		data->julia_y = ft_atod(av[3]);
	}
}

void	mouse_zoom(t_data *data)
{
	double	new_wid;
	double	new_hei;
	double	x_len;
	double	y_len;

	data->map_height = 4;
	data->map_width = 4;
	new_wid = data->zoom * data->map_width;
	new_hei = -1 * data->zoom * data->map_height;
	x_len = data->map_right - data->map_left;
	y_len = data->map_bottom - data->map_top;
	data->map_left = data->map_left + data->mouse_x * x_len / WIN_X
		- data->mouse_x * (new_wid / WIN_X);
	data->map_top = data->map_top + data->mouse_y * y_len / WIN_Y
		- data->mouse_y * (new_hei / WIN_Y);
	data->map_right = data->map_left + new_wid;
	data->map_bottom = data->map_top + new_hei;
}

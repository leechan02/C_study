/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:34:45 by euiclee           #+#    #+#             */
/*   Updated: 2022/11/03 10:42:36 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	color(int n, t_data *data)
{
	int	col;
	int	r;
	int	g;
	int	b;

	r = 10;
	g = 10;
	b = 10;
	if (data->color == 1)
		r = 15;
	else if (data->color == 2)
		g = 15;
	else if (data->color == 3)
		b = 15;
	else if (data->color == 4)
	{
		r = 10;
		g = 10;
		b = 10;
	}
	col = ((n * r) % 256 << 16) + ((n * g) % 256 << 8) + ((n * b) % 256);
	return (col);
}

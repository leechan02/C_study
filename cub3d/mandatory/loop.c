/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:20:08 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/31 11:54:53 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	ray_setting(t_game *cub, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	cub->ray.ray_dir_x = cub->player.dir_x + cub->player.plane_x * camera_x;
	cub->ray.ray_dir_y = cub->player.dir_y + cub->player.plane_y * camera_x;
	cub->map.map_x = (int)cub->player.x;
	cub->map.map_y = (int)cub->player.y;
	if (cub->ray.ray_dir_x == 0)
		cub->ray.delta_dist_x = DBL_MAX;
	else
		cub->ray.delta_dist_x = fabs(1 / cub->ray.ray_dir_x);
	if (cub->ray.ray_dir_y == 0)
		cub->ray.delta_dist_y = DBL_MAX;
	else
		cub->ray.delta_dist_y = fabs(1 / cub->ray.ray_dir_y);
}

void	ray_size_dist_setting(t_game *cub)
{
	if (cub->ray.ray_dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.size_dist_x = (cub->player.x - cub->map.map_x)
			* cub->ray.delta_dist_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.size_dist_x = (cub->map.map_x + 1.0 - cub->player.x)
			* cub->ray.delta_dist_x;
	}
	if (cub->ray.ray_dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.size_dist_y = (cub->player.y - cub->map.map_y)
			* cub->ray.delta_dist_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.size_dist_y = (cub->map.map_y + 1.0 - cub->player.y)
			* cub->ray.delta_dist_y;
	}
}

void	hit_check(t_game *cub)
{
	while (1)
	{
		if (cub->ray.size_dist_x < cub->ray.size_dist_y)
		{
			cub->ray.size_dist_x += cub->ray.delta_dist_x;
			cub->map.map_x += cub->ray.step_x;
			cub->map.side = 0;
		}
		else
		{
			cub->ray.size_dist_y += cub->ray.delta_dist_y;
			cub->map.map_y += cub->ray.step_y;
			cub->map.side = 1;
		}
		if (cub->map.grid[cub->map.map_y][cub->map.map_x] == '1')
			break ;
	}
	if (cub->map.side == 0)
		cub->ray.wall_dist = (cub->map.map_x - cub->player.x
				+ ((1.0 - cub->ray.step_x) / 2)) / cub->ray.ray_dir_x;
	else
		cub->ray.wall_dist = (cub->map.map_y - cub->player.y
				+ ((1.0 - cub->ray.step_y) / 2)) / cub->ray.ray_dir_y;
}

void	draw_point_check(t_game *cub)
{
	cub->draw.draw_height = (int)(HEIGHT / cub->ray.wall_dist);
	cub->draw.draw_start = HEIGHT / 2 - cub->draw.draw_height / 2;
	cub->draw.draw_end = HEIGHT / 2 + cub->draw.draw_height / 2;
	if (cub->draw.draw_start < 0)
		cub->draw.draw_start = 0;
	if (cub->draw.draw_end >= HEIGHT)
		cub->draw.draw_end = HEIGHT - 1;
	if (cub->map.side == 1 && cub->ray.ray_dir_y < 0)
		cub->draw.texture_number = 0;
	if (cub->map.side == 1 && cub->ray.ray_dir_y > 0)
		cub->draw.texture_number = 1;
	if (cub->map.side == 0 && cub->ray.ray_dir_x < 0)
		cub->draw.texture_number = 2;
	if (cub->map.side == 0 && cub->ray.ray_dir_x > 0)
		cub->draw.texture_number = 3;
	if (cub->map.side == 0)
		cub->draw.wall_x = cub->player.y + cub->ray.wall_dist
			* cub->ray.ray_dir_y;
	else
		cub->draw.wall_x = cub->player.x + cub->ray.wall_dist
			* cub->ray.ray_dir_x;
	cub->draw.wall_x -= floor(cub->draw.wall_x);
}

void	put_texture_color(t_game *cub, int x)
{
	int		temp;
	int		texture_y;
	double	step;
	double	texture_position;

	cub->draw.texture_x = (int)(cub->draw.wall_x * TEXWIDTH);
	if (cub->map.side == 0 && cub->ray.ray_dir_x > 0)
		cub->draw.texture_x = TEXWIDTH - cub->draw.texture_x - 1;
	if (cub->map.side == 1 && cub->ray.ray_dir_y < 0)
		cub->draw.texture_x = TEXWIDTH - cub->draw.texture_x - 1;
	step = (double)TEXHEIGHT / (double)cub->draw.draw_height;
	texture_position = (cub->draw.draw_start - (int)(HEIGHT / 2)
			+ (int)(cub->draw.draw_height / 2)) * step;
	temp = cub->draw.draw_start;
	while (temp <= cub->draw.draw_end)
	{
		texture_y = (int)texture_position & (TEXHEIGHT - 1);
		texture_position += step;
		cub->draw.color = cub->tex[cub->draw.texture_number] \
			[TEXHEIGHT * texture_y + cub->draw.texture_x];
		cub->arr_temp[temp][x] = cub->draw.color;
		temp++;
	}
}

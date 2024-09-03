/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:35:27 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/01 15:06:55 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run_bonus.h"

void	key_w_and_s(t_game *cub, double move_speed)
{
	if (cub->key.w)
	{
		if (cub->map.grid[(int)cub->player.y] \
			[(int)(cub->player.x + (cub->player.dir_x * move_speed))] == '0')
			cub->player.x += cub->player.dir_x * move_speed;
		if (cub->map.grid[(int)(cub->player.y
				+ (cub->player.dir_y * move_speed))][(int)cub->player.x] == '0')
			cub->player.y += cub->player.dir_y * move_speed;
	}
	if (cub->key.s)
	{
		if (cub->map.grid[(int)cub->player.y] \
			[(int)(cub->player.x - (cub->player.dir_x * move_speed))] == '0')
			cub->player.x -= cub->player.dir_x * move_speed;
		if (cub->map.grid[(int)(cub->player.y
				- (cub->player.dir_y * move_speed))][(int)cub->player.x] == '0')
			cub->player.y -= cub->player.dir_y * move_speed;
	}
}

void	key_a_and_d(t_game *cub, double move_speed)
{
	if (cub->key.a)
	{
		if (cub->map.grid[(int)cub->player.y] \
			[(int)(cub->player.x - (cub->player.plane_x * move_speed))] == '0')
			cub->player.x -= cub->player.plane_x * move_speed;
		if (cub->map.grid[(int)(cub->player.y - (cub->player.plane_y
					* move_speed))][(int)cub->player.x] == '0')
			cub->player.y -= cub->player.plane_y * move_speed;
	}
	if (cub->key.d)
	{
		if (cub->map.grid[(int)cub->player.y] \
			[(int)(cub->player.x + (cub->player.plane_x * move_speed))] == '0')
			cub->player.x += cub->player.plane_x * move_speed;
		if (cub->map.grid[(int)(cub->player.y + (cub->player.plane_y
					* move_speed))][(int)cub->player.x] == '0')
			cub->player.y += cub->player.plane_y * move_speed;
	}
}

void	key_left(t_game *cub, double rotate_speed)
{
	double	temp_dir_x;
	double	temp_plane_x;

	if (cub->key.left)
	{
		temp_dir_x = cub->player.dir_x;
		cub->player.dir_x = cub->player.dir_x * cos(-rotate_speed)
			- (cub->player.dir_y * sin(-rotate_speed));
		cub->player.dir_y = temp_dir_x * sin(-rotate_speed)
			+ (cub->player.dir_y * cos(-rotate_speed));
		temp_plane_x = cub->player.plane_x;
		cub->player.plane_x = cub->player.plane_x * cos(-rotate_speed)
			- (cub->player.plane_y * sin(-rotate_speed));
		cub->player.plane_y = temp_plane_x * sin(-rotate_speed)
			+ (cub->player.plane_y * cos(-rotate_speed));
	}
}

void	key_right(t_game *cub, double rotate_speed)
{
	double	temp_dir_x;
	double	temp_plane_x;

	if (cub->key.right)
	{
		temp_dir_x = cub->player.dir_x;
		cub->player.dir_x = cub->player.dir_x * cos(rotate_speed)
			- (cub->player.dir_y * sin(rotate_speed));
		cub->player.dir_y = temp_dir_x * sin(rotate_speed)
			+ (cub->player.dir_y * cos(rotate_speed));
		temp_plane_x = cub->player.plane_x;
		cub->player.plane_x = cub->player.plane_x * cos(rotate_speed)
			- (cub->player.plane_y * sin(rotate_speed));
		cub->player.plane_y = temp_plane_x * sin(rotate_speed)
			+ (cub->player.plane_y * cos(rotate_speed));
	}
}

void	key_check(t_game *cub)
{
	double	move_speed;
	double	rotate_speed;

	move_speed = 0.03;
	rotate_speed = 0.03;
	key_w_and_s(cub, move_speed);
	key_a_and_d(cub, move_speed);
	key_left(cub, rotate_speed);
	key_right(cub, rotate_speed);
}

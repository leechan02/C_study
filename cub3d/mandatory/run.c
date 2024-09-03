/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:40:01 by yeham             #+#    #+#             */
/*   Updated: 2023/03/30 17:05:34 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

int	loop(t_game *cub)
{
	int	x;

	x = 0;
	mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
	painting_floor(cub);
	while (x < WIDTH)
	{
		ray_setting(cub, x);
		ray_size_dist_setting(cub);
		hit_check(cub);
		draw_point_check(cub);
		put_texture_color(cub, x);
		x++;
	}
	key_check(cub);
	painting(cub);
	return (0);
}

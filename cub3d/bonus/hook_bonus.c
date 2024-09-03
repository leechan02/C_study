/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:52:34 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/30 19:28:42 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run_bonus.h"

int	x_exit(t_game *cub)
{
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	free_all(cub);
	exit(0);
}

int	key_press(int key, t_game *cub)
{
	if (key == 53)
		x_exit(cub);
	if (key == 0)
		cub->key.a = 1;
	if (key == 1)
		cub->key.s = 1;
	if (key == 2)
		cub->key.d = 1;
	if (key == 13)
		cub->key.w = 1;
	if (key == 123)
		cub->key.left = 1;
	if (key == 124)
		cub->key.right = 1;
	return (0);
}

int	key_release(int key, t_game *cub)
{
	if (key == 0)
		cub->key.a = 0;
	if (key == 1)
		cub->key.s = 0;
	if (key == 2)
		cub->key.d = 0;
	if (key == 13)
		cub->key.w = 0;
	if (key == 123)
		cub->key.left = 0;
	if (key == 124)
		cub->key.right = 0;
	return (0);
}

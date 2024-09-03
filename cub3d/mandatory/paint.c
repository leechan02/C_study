/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:48:40 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/30 12:57:39 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	painting(t_game *cub)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			cub->mlx.addr[k] = cub->arr_temp[i][j];
			j++;
			k++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
}

void	painting_floor(t_game *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				cub->arr_temp[i][j] = cub->ceiling_color;
			else
				cub->arr_temp[i][j] = cub->floor_color;
			j++;
		}
		i++;
	}
}

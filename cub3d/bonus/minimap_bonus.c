/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:29 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/01 15:03:54 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run_bonus.h"

void	put_minimap(t_game *cub)
{
	int		i;
	int		j;
	int		minimap_height;
	int		minimap_width;

	minimap_height = cub->map.height * 10;
	minimap_width = cub->map.width * 10;
	if (minimap_height > HEIGHT || minimap_width > WIDTH)
	{
		write(2, "Error minimap\n", 14);
		x_exit(cub);
	}
	i = 0;
	while (i < minimap_height)
	{
		j = 0;
		while (j < minimap_width)
		{
			cub->arr_temp[i][j] = 0X000000;
			if (cub->map.minimap[(int)(0.1 * i)][(int)(0.1 * j)] == '0')
				cub->arr_temp[i][j] = 0XFFFFFF;
			j++;
		}
		i++;
	}
}

void	put_minimap_player(t_game *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			cub->arr_temp[(int)((cub->player.y - 0.5) * 10) + i] \
				[(int)((cub->player.x - 0.5) * 10) + j] = 0XFF0000;
			j++;
		}
		i++;
	}
}

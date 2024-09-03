/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:05:38 by yeham             #+#    #+#             */
/*   Updated: 2023/03/31 18:50:29 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/run.h"

void	load_img(t_game *cub, int *tex, char *path)
{
	int	i;

	i = 0;
	cub->mlx.img = 0;
	cub->mlx.img = mlx_xpm_file_to_image
		(cub->mlx.mlx, path, &cub->mlx.img_width, &cub->mlx.img_height);
	if (cub->mlx.img == 0)
	{
		write(2, "Error xpm file\n", 15);
		exit(1);
	}
	cub->mlx.addr = (int *)mlx_get_data_addr(cub->mlx.img,
			&cub->mlx.bits_per_pixel, &cub->mlx.line_length, &cub->mlx.endian);
	while (i < cub->mlx.img_height * cub->mlx.img_width)
	{
			tex[i] = cub->mlx.addr[i];
			i++;
	}
	mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
}

void	setting_detail(t_game *cub)
{
	load_img(cub, cub->tex[0], cub->tex_path[0]);
	load_img(cub, cub->tex[1], cub->tex_path[1]);
	load_img(cub, cub->tex[2], cub->tex_path[2]);
	load_img(cub, cub->tex[3], cub->tex_path[3]);
}

void	setting_all(t_game *cub)
{
	int	i;

	i = -1;
	cub->arr_temp = malloc(sizeof(int *) * HEIGHT);
	if (!cub->arr_temp)
		exit(1);
	while (++i < HEIGHT)
	{
		if (i < 4)
			cub->tex[i] = malloc(sizeof(int) * TEXWIDTH * TEXWIDTH);
		if (i < 4 && !cub->tex[i])
			exit(1);
		cub->arr_temp[i] = malloc(sizeof(int) * WIDTH);
		if (!cub->arr_temp[i])
			exit(1);
	}
	setting_detail(cub);
}

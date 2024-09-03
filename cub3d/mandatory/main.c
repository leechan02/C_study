/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeham <yeham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:25:15 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/01 15:05:46 by yeham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"
#include "../includes/run.h"

int	main(int ac, char **av)
{
	t_game	cub;

	if (ac != 2)
		return (ft_putstr_fd("Error: invalid arguments\n", 2), EXIT_FAILURE);
	ft_memset(&cub, 0, sizeof(t_game));
	if (parse(av[1], &cub))
		return (ft_putstr_fd("Error: wrong map\n", 2), EXIT_FAILURE);
	cub.mlx.mlx = mlx_init();
	setting_all(&cub);
	cub.mlx.win = mlx_new_window(cub.mlx.mlx, WIDTH, HEIGHT, "cub3d");
	cub.mlx.img = mlx_new_image(cub.mlx.mlx, WIDTH, HEIGHT);
	cub.mlx.addr = (int *)mlx_get_data_addr(cub.mlx.img,
			&cub.mlx.bits_per_pixel, &cub.mlx.line_length, &cub.mlx.endian);
	mlx_hook(cub.mlx.win, 17, 0, x_exit, &cub);
	mlx_hook(cub.mlx.win, 2, 1, key_press, &cub);
	mlx_hook(cub.mlx.win, 3, 2, key_release, &cub);
	mlx_loop_hook(cub.mlx.mlx, &loop, &cub);
	mlx_loop(cub.mlx.mlx);
	return (EXIT_SUCCESS);
}

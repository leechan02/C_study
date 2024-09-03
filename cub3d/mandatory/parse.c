/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:25:53 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/30 19:01:27 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	name_check(char *file)
{
	char	*point;

	point = ft_strrchr(file, '.');
	if (ft_strcmp(".cub", point) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	parse(char *file, t_game *game)
{
	t_parse	p;

	if (name_check(file))
		return (EXIT_FAILURE);
	p.fd = open(file, O_RDONLY);
	if (p.fd < 0 || read(p.fd, NULL, 0) < 0)
	{
		ft_putstr_fd("Error: fail to open\n", 2);
		exit(1);
	}
	ft_memset(game->tex_path, 0, sizeof(char *) * 4);
	if (scan_map(&p, game))
		return (EXIT_FAILURE);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		exit(1);
	ft_memset(game->map.grid, 0, sizeof(char *) * (game->map.height + 1));
	if (parse_map(file, game, p.line_cnt))
		return (free_map(game), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

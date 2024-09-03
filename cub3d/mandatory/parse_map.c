/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:06:09 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/01 14:16:40 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

void	vector_player(t_game *game, int i, int j, char **grid)
{
	if (grid[i][j] == 'N')
	{
		game->player.dir_y = -1;
		game->player.plane_x = 1;
	}
	else if (grid[i][j] == 'S')
	{
		game->player.dir_y = 1;
		game->player.plane_x = -1;
	}
	else if (grid[i][j] == 'E')
	{
		game->player.dir_x = 1;
		game->player.plane_y = 1;
	}
	else if (grid[i][j] == 'W')
	{
		game->player.dir_x = -1;
		game->player.plane_y = -1;
	}
	game->map.grid[i][j] = '0';
}

int	surround_check(t_game *game, int i, size_t j, char **grid)
{
	int	k;

	k = 0;
	if (grid[i][j] != '0')
	{
		if ((int)game->player.x || (int)game->player.y)
			return (EXIT_FAILURE);
		game->player.x = (double)j + 0.5;
		game->player.y = (double)i + 0.5;
		vector_player(game, i, j, grid);
	}
	if (i == 0 || i == game->map.height - 1
		|| ft_strlen(grid[i]) - 1 == (unsigned long)j)
		return (EXIT_FAILURE);
	while (grid[i][k] == ' ')
		k++;
	if (grid[i][k] == '0')
		return (EXIT_FAILURE);
	if (i != 0 && i != game->map.height - 1)
		if (j >= ft_strlen(grid[i - 1]) || j >= ft_strlen(grid[i + 1])
			|| grid[i - 1][j] == ' ' || grid[i + 1][j] == ' '
			|| grid[i][j - 1] == ' ' || grid[i][j + 1] == ' ')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	wall_check(t_game *game)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (++i < game->map.height)
	{
		tmp = game->map.grid[i];
		if (tmp != NULL && ft_stronly(tmp, "01NSEW") == 0)
			return (EXIT_FAILURE);
		j = 0;
		while (tmp[j])
		{
			while (tmp[j] == ' ')
				j++;
			if (tmp[j] == '0' || tmp[j] == 'N' || tmp[j] == 'S' || tmp[j] == 'E'
				|| tmp[j] == 'W')
				if (surround_check(game, i, j, game->map.grid))
					return (EXIT_FAILURE);
			j++;
		}
	}
	if ((int)game->player.x == 0 || (int)game->player.y == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	parse_map(char *file, t_game *game, int map_line)
{
	int		i;
	t_parse	p;

	p.fd = open(file, O_RDONLY);
	p.stop = 0;
	i = 0;
	p.line = get_next_line(p.fd);
	while (p.line != NULL)
	{
		if (p.line != NULL && p.stop >= map_line)
		{
			game->map.grid[i] = p.line;
			if (p.line[ft_strlen(p.line) - 1] == '\n')
				p.line[ft_strlen(p.line) - 1] = '\0';
			i++;
		}
		if (p.stop < map_line)
			free(p.line);
		p.stop++;
		p.line = get_next_line(p.fd);
	}
	return (wall_check(game));
}

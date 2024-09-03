/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:42:32 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/31 19:01:36 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

int	c_p(char *file)
{
	char	*point;
	char	*temp;
	int		fd;

	temp = ft_strtrim(file, "\n");
	point = ft_strrchr(temp, '.');
	if (ft_strcmp(".xpm", point))
		return (free(temp), FALSE);
	fd = open(temp, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (free(temp), FALSE);
	return (free(temp), TRUE);
}

void	map_size(char *line, t_game *game, int *stop)
{
	int	i;

	i = 0;
	*stop = 1;
	while (line[i] && line[i] != '\n')
		i++;
	if (game->map.width < i)
		game->map.width = i;
	game->map.height++;
}

int	parse_color(char **word, t_game *game, char flag)
{
	int		color[4];
	char	**num;

	if (ft_strtarget(word[1], ",0123456789") == 0)
		return (free(word), EXIT_FAILURE);
	if (ft_strchrnum(word[1], ',') != 2)
		return (free(word), EXIT_FAILURE);
	num = ft_split(word[1], ',');
	if (!(ft_isstrdigit(num[0]) && ft_isstrdigit(num[1])
			&& ft_isstrdigit(num[2])) || num[3] != NULL)
		return (free_s(num), free_s(word), EXIT_FAILURE);
	color[0] = ft_atoi(num[0]);
	color[1] = ft_atoi(num[1]);
	color[2] = ft_atoi(num[2]);
	if (color[0] > 255 || color[1] > 255 || color[2] > 255
		|| color[0] < 0 || color[1] < 0 || color[2] < 0)
		return (free_s(num), free_s(word), EXIT_FAILURE);
	color[3] = (color[0] << 16) + (color[1] << 8) + color[2];
	if (flag == 'F')
		game->floor_color = color[3];
	else if (flag == 'C')
		game->ceiling_color = color[3];
	return (free_s(num), free_s(word), EXIT_SUCCESS);
}

int	parse_element(char *line, t_game *game, int *element_cnt)
{
	char	**word;

	if (*line == '\n')
		return (EXIT_SUCCESS);
	word = ft_split(line, ' ');
	(*element_cnt)++;
	if (word[2] != NULL)
		return (free(line), free_s(word), EXIT_FAILURE);
	if (!ft_strcmp("NO", word[0]) && !game->tex_path[0] && c_p(word[1]))
		game->tex_path[0] = ft_strtrim(word[1], "\n");
	else if (!ft_strcmp("SO", word[0]) && !game->tex_path[1] && c_p(word[1]))
		game->tex_path[1] = ft_strtrim(word[1], "\n");
	else if (!ft_strcmp("WE", word[0]) && !game->tex_path[2] && c_p(word[1]))
		game->tex_path[2] = ft_strtrim(word[1], "\n");
	else if (!ft_strcmp("EA", word[0]) && !game->tex_path[3] && c_p(word[1]))
		game->tex_path[3] = ft_strtrim(word[1], "\n");
	else if (!ft_strcmp("F", word[0]) && !game->floor_color)
		return (parse_color(word, game, 'F'));
	else if (!ft_strcmp("C", word[0]) && !game->ceiling_color)
		return (parse_color(word, game, 'C'));
	else
		return (free(line), free_path(game), free_s(word)
			, (*element_cnt)--, EXIT_FAILURE);
	return (free_s(word), EXIT_SUCCESS);
}

int	scan_map(t_parse *p, t_game *game)
{
	p->element_cnt = 0;
	p->line_cnt = 0;
	p->stop = 0;
	ft_memset(&(game->map), 0, sizeof(t_map));
	p->line = get_next_line(p->fd);
	while (p->line != NULL)
	{
		if (p->line != NULL && p->element_cnt < 6)
		{
			if (parse_element(p->line, game, &p->element_cnt))
				return (close(p->fd), EXIT_FAILURE);
		}
		else if (p->line != NULL && ft_strtarget(p->line, " 01NSEW"))
			map_size(p->line, game, &p->stop);
		else if (p->line != NULL && *p->line != '\n')
			return (free_path(game), free(p->line), close(p->fd), EXIT_FAILURE);
		if (p->stop == 0)
			p->line_cnt++;
		free(p->line);
		p->line = get_next_line(p->fd);
	}
	close(p->fd);
	return (EXIT_SUCCESS);
}

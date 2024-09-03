/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:23:18 by euiclee           #+#    #+#             */
/*   Updated: 2023/04/01 14:19:33 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "cub3d_bonus.h"

typedef struct s_parse{
	int		fd;
	char	*line;
	int		element_cnt;
	int		line_cnt;
	int		stop;
}t_parse;

/*parse*/
int		name_check(char *file);
int		parse(char *file, t_game *game);

/*parse_map*/
int		wall_check(t_game *game);
int		parse_map(char *file, t_game *game, int map_line);
int		surround_check(t_game *game, int i, size_t j, char **grid);

void	vector_player(t_game *game, int i, int j, char **grid);

/*parse_elements*/
int		c_p(char *file);
int		scan_map(t_parse *p, t_game *game);
int		parse_color(char **word, t_game *game, char flag);
int		parse_element(char *line, t_game *game, int *element_cnt);

void	map_size(char *line, t_game *game, int *stop);
#endif
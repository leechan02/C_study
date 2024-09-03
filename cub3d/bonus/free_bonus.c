/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:57:50 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/31 22:43:00 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	free_all(t_game *cub)
{
	int	i;

	i = 0;
	while (cub->arr_temp && i < HEIGHT)
	{
		if (cub->arr_temp[i])
		{
			free(cub->arr_temp[i]);
			cub->arr_temp[i] = NULL;
		}
		i++;
	}
	free(cub->arr_temp);
	cub->arr_temp = NULL;
	i = 0;
	while (i < 4)
	{
		if (cub->tex[i])
		{
			free(cub->tex[i]);
			cub->tex[i] = NULL;
		}
		i++;
	}
	return (free_map(cub), free_minimap(cub), free_path(cub));
}

void	free_map(t_game *cub)
{
	int	i;

	i = 0;
	while (i < cub->map.height)
	{
		if (cub->map.grid[i] != NULL)
		{
			free(cub->map.grid[i]);
			cub->map.grid[i] = NULL;
		}
		i++;
	}
	free(cub->map.grid);
	cub->map.grid = NULL;
}

void	free_minimap(t_game *cub)
{
	int	i;

	i = 0;
	while (i < cub->map.height)
	{
		if (cub->map.minimap[i] != NULL)
		{
			free(cub->map.minimap[i]);
			cub->map.minimap[i] = NULL;
		}
		i++;
	}
	free(cub->map.minimap);
	cub->map.minimap = NULL;
}

void	free_path(t_game *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->tex_path[i] != NULL)
		{
			free(cub->tex_path[i]);
			cub->tex_path[i] = NULL;
		}
		i++;
	}
}

void	free_s(char **word)
{
	int	i;

	i = 0;
	while (word[i] != NULL)
	{
		free(word[i]);
		word[i] = NULL;
		i++;
	}
	free(word);
	word = NULL;
}

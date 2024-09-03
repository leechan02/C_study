/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:23:18 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/31 11:53:28 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>

# define TEXWIDTH 256
# define TEXHEIGHT 256
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			map_x;
	int			map_y;
	int			side;
}				t_map;

typedef struct s_key
{
	int		w;
	int		s;
	int		a;
	int		d;
	int		left;
	int		right;
}				t_key;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_ray
{
	int			step_x;
	int			step_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		size_dist_x;
	double		size_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		wall_dist;
}				t_ray;

typedef struct s_draw
{
	int		draw_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		texture_number;
	int		texture_x;
	double	wall_x;
}				t_draw;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		img_width;
	int		img_height;
	int		endian;
}				t_mlx;

typedef struct s_game
{
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_draw		draw;
	t_mlx		mlx;
	t_key		key;
	char		*tex_path[4];
	int			*tex[4];
	int			floor_color;
	int			ceiling_color;
	int			**arr_temp;
}				t_game;

/*free*/
void	free_path(t_game *cub);
void	free_map(t_game *cub);
void	free_all(t_game *game);
void	free_s(char **word);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:31:51 by euiclee           #+#    #+#             */
/*   Updated: 2023/03/30 19:34:13 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_BONUS_H
# define RUN_BONUS_H

# include "cub3d_bonus.h"

/*run*/
int		loop(t_game *cub);

/*loop*/
void	hit_check(t_game *cub);
void	draw_point_check(t_game *cub);
void	ray_setting(t_game *cub, int x);
void	ray_size_dist_setting(t_game *cub);
void	put_texture_color(t_game *cub, int x);

/*paint*/
void	painting(t_game *cub);
void	painting_floor(t_game *cub);

/*hook*/
int		x_exit(t_game *cub);
int		key_press(int key, t_game *cub);
int		key_release(int key, t_game *cub);

/*key*/
void	key_check(t_game *cub);
void	key_w_and_s(t_game *cub, double move_speed);
void	key_a_and_d(t_game *cub, double move_speed);
void	key_left(t_game *cub, double rotate_speed);
void	key_right(t_game *cub, double rotate_speed);

/*setting*/
void	map_copy(t_game *cub);
void	setting_all(t_game *cub);
void	fill_temp_map(t_game *cub);
void	setting_detail(t_game *cub);
void	load_img(t_game *cub, int *tex, char *path);

/*minimap*/
void	put_minimap(t_game *cub);
void	put_minimap_player(t_game *cub);

#endif
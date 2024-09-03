/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:20:56 by euiclee           #+#    #+#             */
/*   Updated: 2022/11/14 09:31:21 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

# define WIN_X 500
# define WIN_Y 500
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define MOUSE_MOVE 6
# define X_BUTTON 17
# define N_MAX 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		color;
	int		param;
	int		key;
	double	temp;
	double	temp2;
	double	mv_x;
	double	mv_y;
	double	real;
	double	imag;
	double	zoom;
	double	map_x;
	double	map_y;
	double	map_left;
	double	map_top;
	double	map_bottom;
	double	map_right;
	double	map_height;
	double	map_width;
	double	mouse_x;
	double	mouse_y;
	double	julia_x;
	double	julia_y;
}	t_data;

/*fractol*/
void	print_list(void);

int		close_window(void);
int		main(int ac, char **av);

/*mandelbrot*/
void	mandelbrot(void);
void	init_mandel(t_data *data);
void	make_mandel(t_data *data);

int		mandel_key(int keycode, t_data *data);
int		mandel_mouse(int keycode, int x, int y, t_data *data);

/*tricorn*/
void	tricorn(void);
void	init_tricorn(t_data *data);
void	make_tricorn(t_data *data);

int		tricorn_key(int keycode, t_data *data);
int		tricorn_mouse(int keycode, int x, int y, t_data *data);

/*julia*/
void	julia(int ac, char **av);
void	init_julia(t_data *data, double x, double y);
void	make_julia(t_data *data);

int		julia_key(int keycode, t_data *data);
int		julia_mouse(int keycode, int x, int y, t_data *data);

/*utils*/
void	mouse_zoom(t_data *data);
void	param_check(int ac, char **av, t_data *data);
void	hook_keycode(int keycode, t_data *data);
void	hook_mouse(int keycode, int x, int y, t_data *data);

/*color*/
int		color(int n, t_data *data);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif

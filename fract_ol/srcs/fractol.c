/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:25:30 by euiclee           #+#    #+#             */
/*   Updated: 2022/11/07 08:58:50 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_window(void)
{
	exit (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_list(void)
{
	printf("-----------------------------\n");
	printf("Parameters example : \n\n");
	printf("1) mandelbrot\n");
	printf("2) julia\n");
	printf("3) tricorn\n");
	printf("-----------------------------\n");
}

int	main(int ac, char **av)
{
	if (ac < 5 && ac > 1)
	{
		if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
			mandelbrot();
		else if ((ac == 2 || ac == 4) && ft_strcmp(av[1], "julia") == 0)
			julia(ac, av);
		else if (ac == 2 && ft_strcmp(av[1], "tricorn") == 0)
			tricorn();
		else
			print_list();
	}
	else
		print_list();
	return (0);
}

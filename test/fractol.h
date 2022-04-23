/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:54:30 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/18 21:54:31 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H

#define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
#define WIDTH 700
#define HEIGHT 700

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fractol{
	void	*mlx;
	void	*mlx_win;
	double	c_r;
	double	c_i;
	double	z_r;
	double 	z_i;
	double	x;
	double	y;
	double	a;
	double	b;
	double	x_r;
	double	y_r;
	double	x_i;
	double	y_i;
	double	iteration;
	double	max_iteration;
	double	new_color;
	double	color;
	t_image	image;
}	t_fractol;

void	ft_draw();
void	ft_launch();
double	ft_map(int in, double in_end, double out_start, double out_end);

#endif
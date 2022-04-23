/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:49:37 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/18 18:16:38 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	myhook(int keycode, t_fractol *data)
{
	if (keycode == 126)
	{
		data->y_r += 0.2;
		data->y_i += 0.2;
	}
	else if (keycode == 124)
	{
		data->x_r -= 0.2;
		data->x_i -= 0.2;
	}
	else if (keycode == 125)
	{
		data->y_r -= 0.2;
		data->y_i -= 0.2;
	}
	else if (keycode == 123)
	{
		data->x_r += 0.2;
		data->x_i += 0.2;
	}
	ft_draw(data);
	return (0);
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double	ft_map(int in, double in_end, double out_start, double out_end)
{
	double	mapped_val;

	mapped_val = out_start + ((out_end - out_start) / in_end) * in;
	return (mapped_val);
}

void	ft_draw(t_fractol *data)
{
	mlx_clear_window(data->mlx ,data->mlx_win);
	data->y = 0;
	data->max_iteration = 100;
	data->color = 0xff6600;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			data->a = ft_map(data->x, WIDTH, data->x_i, data->x_r);
			data->b = ft_map(data->y, HEIGHT, data->y_i, data->y_r);
			data->c_r = data->a;
			data->c_i = data->b;
			
			data->iteration = 0;
			data->new_color = 0;
			while (data->iteration < data->max_iteration)
			{
				data->z_r = data->a * data->a - data->b * data->b;
				data->z_i = 2 * data->a * data->b;
				data->a = data->z_r + data->c_r;
				data->b = data->z_i + data->c_i;
				data->iteration++;
				if (data->a * data->a + data->b * data->b > 4)
					break;
			}
			if (data->iteration < data->max_iteration)
				data->new_color = data->color * data->iteration;
			// mlx_pixel_put(data->mlx, data->mlx_win, data->x, data->y, data->color);
			my_mlx_pixel_put(&data->image , data->x, data->y, data->new_color);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.img, 0, 0);
}

void	ft_launch()
{
	t_fractol	*data;

	data = malloc(sizeof(t_fractol));
	data->x_r = 2;
	data->y_r = 2;
	data->x_i = -2;
	data->y_i = -2;
	data->mlx  = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FRACTOL");
	data->image.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bits_per_pixel, &data->image.line_length, &data->image.endian);
	ft_draw(data);
	mlx_hook(data->mlx_win, 2, 0, myhook, data);
	mlx_loop(data->mlx);
}
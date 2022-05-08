/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:08:19 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/29 13:03:40 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_put_image(t_var *game, int i, int j)
{
	while (game->map[i][j])
	{
		if (game->map[i][j] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->mlx_coin1,
				j * 50, i * 50);
		else if (game->map[i][j] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->mlx_player,
				j * 50, i * 50);
		else if (game->map[i][j] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->mlx_space,
				j * 50, i * 50);
		else if (game->map[i][j] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->mlx_wall,
				j * 50, i * 50);
		else if (game->map[i][j] == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->mlx_space,
				j * 50, i * 50);
		else if (game->map[i][j] == 'X')
			mlx_put_image_to_window(game->mlx, game->win, game->mlx_enemy,
				j * 50, i * 50);
		j++;
	}
}

void	file_to_image(t_var	*game)
{
	game->mlx_wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &game->img_w, &game->img_h);
	game->mlx_player = mlx_xpm_file_to_image(game->mlx,
			"./img/player_f1.xpm", &game->img_w, &game->img_h);
	game->mlx_player1 = mlx_xpm_file_to_image(game->mlx,
			"./img/player_f2.xpm", &game->img_w, &game->img_h);
	game->mlx_space = mlx_xpm_file_to_image(game->mlx,
			"./img/space.xpm", &game->img_w, &game->img_h);
	game->mlx_coin1 = mlx_xpm_file_to_image(game->mlx,
			"./img/coins1.xpm", &game->img_w, &game->img_h);
	game->mlx_coin2 = mlx_xpm_file_to_image(game->mlx,
			"./img/coins2.xpm", &game->img_w, &game->img_h);
	game->mlx_coin3 = mlx_xpm_file_to_image(game->mlx,
			"./img/coins3.xpm", &game->img_w, &game->img_h);
	game->mlx_coin4 = mlx_xpm_file_to_image(game->mlx,
			"./img/coins4.xpm", &game->img_w, &game->img_h);
	game->mlx_coin5 = mlx_xpm_file_to_image(game->mlx,
			"./img/coins5.xpm", &game->img_w, &game->img_h);
	game->mlx_coin6 = mlx_xpm_file_to_image(game->mlx,
			"./img/coins6.xpm", &game->img_w, &game->img_h);
	game->mlx_enemy = mlx_xpm_file_to_image(game->mlx,
			"./img/enemy.xpm", &game->img_w, &game->img_h);
	game->mlx_exit = mlx_xpm_file_to_image(game->mlx,
			"./img/exit.xpm", &game->img_w, &game->img_h);
}

void	draw_bonus(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	game->move = 0;
	file_to_image(game);
	while (game->map[i])
	{
		j = 0;
		ft_put_image(game, i, j);
		i++;
	}
}

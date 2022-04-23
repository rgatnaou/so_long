/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:09:45 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/23 23:23:31 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_var *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->mlx_wall,
			j * 50, i * 50);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->mlx_space,
			j * 50, i * 50);
	else if (game->map[i][j] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->mlx_coin,
			j * 50, i * 50);
		game->n++;
	}
	else if (game->map[i][j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->mlx_player,
			j * 50, i * 50);
		game->i_p = i;
		game->j_p = j;
	}
	else if (game->map[i][j] == 'E')
	{	
		mlx_put_image_to_window(game->mlx, game->win, game->mlx_space,
			j * 50, i * 50);
		game->i_e = i;
		game->j_e = j;
	}
}

void	draw(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	game->n = 0;
	game->move = 0;
	game->mlx_wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &game->img_w, &game->img_h);
	game->mlx_player = mlx_xpm_file_to_image(game->mlx,
			"./img/player.xpm", &game->img_w, &game->img_h);
	game->mlx_space = mlx_xpm_file_to_image(game->mlx,
			"./img/space.xpm", &game->img_w, &game->img_h);
	game->mlx_coin = mlx_xpm_file_to_image(game->mlx,
			"./img/coin.xpm", &game->img_w, &game->img_h);
	game->mlx_exit = mlx_xpm_file_to_image(game->mlx,
			"./img/exit.xpm", &game->img_w, &game->img_h);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			ft_put_image(game, i, j);
			j++;
		}
		i++;
	}
}

void	ft_move(t_var *game, int pos_i, int pos_j)
{
		
	if (game->map[pos_i][pos_j] != '1')
	{
		game->move++;
		mlx_put_image_to_window(game->mlx, game->win, game->mlx_space,
			game->j_p * 50, game->i_p * 50);
		game->i_p = pos_i;
		game->j_p = pos_j;
		if (game->i_p == game->i_e && game->j_p == game->j_e)
			exit(0);
		if (game->map[pos_i][pos_j] == 'C')
		{
			game->n--;
			if (!game->n)
				mlx_put_image_to_window(game->mlx, game->win, game->mlx_exit,
			game->j_e * 50, game->i_e * 50);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->mlx_player,
			game->j_p * 50, game->i_p * 50);
	}
}

int	key_hook(int keycode, t_var *game)
{

	if (keycode == KEY_W)
		ft_move(game, game->i_p - 1, game->j_p);
	else if (keycode == KEY_D)
		ft_move(game, game->i_p, game->j_p + 1);
	else if (keycode == KEY_A)
		ft_move(game, game->i_p, game->j_p - 1);
	else if (keycode == KEY_S)
		ft_move(game, game->i_p + 1, game->j_p);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	mlx_string_put(game->mlx, game->win, 10 , 10 , 0xffffff, ft_itoa(game->move));
	printf("%d\n",game->move);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:09:45 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/29 13:24:06 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_var *game, int i, int j)
{
	while (game->map[i][j])
	{
		if (game->map[i][j] == 'C')
			mlx_put_image_to_window(game->mlx, game->win, game->mlx_coin,
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
		j++;
	}
}

void	put_exit(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	if (!(game->c))
	{
		while (game->map[i])
		{
			j = 0;
			while (game->map[i][j])
			{
				if (game->map[i][j] == 'E')
					mlx_put_image_to_window(game->mlx, game->win,
						game->mlx_exit, j * 50, i * 50);
				j++;
			}
			i++;
		}
	}
}

void	draw(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	game->move = 0;
	game->mlx_wall = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &game->img_w, &game->img_h);
	game->mlx_player = mlx_xpm_file_to_image(game->mlx,
			"./img/player.xpm", &game->img_w, &game->img_h);
	game->mlx_space = mlx_xpm_file_to_image(game->mlx,
			"./img/space.xpm", &game->img_w, &game->img_h);
	game->mlx_coin = mlx_xpm_file_to_image(game->mlx,
			"./img/coins1.xpm", &game->img_w, &game->img_h);
	game->mlx_exit = mlx_xpm_file_to_image(game->mlx,
			"./img/exit.xpm", &game->img_w, &game->img_h);
	while (game->map[i])
	{
		j = 0;
		ft_put_image(game, i, j);
		i++;
	}
}

void	ft_move(t_var *game, int pos_i, int pos_j)
{
	char	*move;

	game->move++;
	mlx_put_image_to_window(game->mlx, game->win, game->mlx_space,
		game->j_p * 50, game->i_p * 50);
	game->i_p = pos_i;
	game->j_p = pos_j;
	if (game->map[game->i_p][game->j_p] == 'E' && !game->c)
		ft_free(game->map, "you win !!\n");
	if (game->map[pos_i][pos_j] == 'C')
	{
		game->map[pos_i][pos_j] = '0';
		game->c--;
		put_exit(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->mlx_player,
		pos_j * 50, pos_i * 50);
	move = ft_itoa(game->move);
	write(1, move, ft_strlen(move));
	write(1, "\n", 1);
	free(move);
}

int	key_hook(int keycode, t_var *game)
{
	if (keycode == KEY_W && game->map[game->i_p - 1][game->j_p] != '1')
		ft_move(game, game->i_p - 1, game->j_p);
	else if (keycode == KEY_D && game->map[game->i_p][game->j_p + 1] != '1')
		ft_move(game, game->i_p, game->j_p + 1);
	else if (keycode == KEY_A && game->map[game->i_p][game->j_p - 1] != '1')
		ft_move(game, game->i_p, game->j_p - 1);
	else if (keycode == KEY_S && game->map[game->i_p + 1][game->j_p] != '1')
		ft_move(game, game->i_p + 1, game->j_p);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		ft_free(game->map, "exit map!!\n");
		exit(0);
	}
	return (0);
}

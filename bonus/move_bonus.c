/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:06:43 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/29 13:00:07 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if (game->map[game->i_p][game->j_p] == 'X')
		ft_free(game->map, "you loss !!\n");
	if (game->map[pos_i][pos_j] == 'C')
	{
		game->map[pos_i][pos_j] = '0';
		game->c--;
		put_exit(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->mlx_player,
		pos_j * 50, pos_i * 50);
	move = ft_itoa(game->move);
	mlx_put_image_to_window(game->mlx, game->win, game->mlx_wall, 0, 0);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xffffff, move);
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

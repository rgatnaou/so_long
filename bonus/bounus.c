/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:37:37 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/29 14:43:35 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	put_coin(t_var *game, int i, int j)
{
	int static	k;

	if (k <= 25)
		mlx_put_image_to_window(game->mlx, game->win,
			game->mlx_coin1, j * 50, i * 50);
	else if (k <= 50)
		mlx_put_image_to_window(game->mlx, game->win,
			game->mlx_coin2, j * 50, i * 50);
	else if (k <= 80)
		mlx_put_image_to_window(game->mlx, game->win,
			game->mlx_coin3, j * 50, i * 50);
	else if (k <= 100)
		mlx_put_image_to_window(game->mlx, game->win,
			game->mlx_coin4, j * 50, i * 50);
	else if (k <= 120)
		mlx_put_image_to_window(game->mlx, game->win,
			game->mlx_coin5, j * 50, i * 50);
	else if (k <= 140)
		mlx_put_image_to_window(game->mlx, game->win,
			game->mlx_coin6, j * 50, i * 50);
	else if (k <= 160)
		k = 0;
	k++;
}

void	ft_coin(t_var *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				put_coin(game, i, j);
			j++;
		}
		i++;
	}
}

int	update(t_var *game)
{
	int static	i;

	if (i <= 25)
		mlx_put_image_to_window(game->mlx, game->win, game->mlx_player,
			game->j_p * 50, game->i_p * 50);
	else if (i <= 50)
		mlx_put_image_to_window(game->mlx, game->win, game->mlx_player1,
			game->j_p * 50, game->i_p * 50);
	else if (i == 80)
		i = 0;
	if (game->c)
		ft_coin(game);
	i++;
	return (0);
}

int	destroy_win(t_var *game)
{
	ft_free(game->map, "exit map !!");
	exit(0);
}

int	main(int ac, char **av)
{
	t_var	game;

	if (ac != 2)
	{
		write(2, "Erorr : invalid args\n", 21);
		exit(1);
	}
	game = check_map(av);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.j * 50, game.i * 50, "so_long");
	draw_bonus(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, destroy_win, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}

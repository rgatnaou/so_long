/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:53:57 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/05/08 17:16:02 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	draw(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, destroy_win, &game);
	mlx_loop(game.mlx);
	return (0);
}

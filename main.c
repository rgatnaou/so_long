/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:53:57 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/23 22:36:45 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_erorr(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	main(int ac, char **av)
{
	t_var	game;

	game = check_map(ac, av);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx , game.j * 50, game.i * 50 , "so_long");
	draw(&game);
	mlx_key_hook(game.win,key_hook,&game);
	mlx_loop(game.mlx);
	
	return (0);
}

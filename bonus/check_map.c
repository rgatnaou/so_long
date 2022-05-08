/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:45:50 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/28 22:22:14 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_read(char **av)
{
	int		fd;
	char	*join;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd == -1 || ft_strnchar(av[1], ".ber"))
	{
		write(2, "Erorr : map failer\n", 19);
		exit(1);
	}
	join = get_next_line(fd);
	if (!join)
	{
		write(2, "Erorr : emty map\n", 17);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		join = ft_strjoin(join, line);
		free(line);
		line = get_next_line(fd);
	}
	return (join);
}

int	check_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[0]);
	while (map[i])
	{
		if (j != (int)ft_strlen(map[i]))
			return (0);
		i++;
	}
	i--;
	j = 0;
	while (map[i][j])
	{
		if (map[0][j] != '1' || map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_car_1(char **map)
{
	int		j;
	int		i;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][j++] != '1')
			return (0);
		while (map[i][j + 1])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'X')
				return (0);
			j++;
		}
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_car_2(t_var *game, int e, int p)
{
	while (game->map[game->i])
	{
		game->j = 0;
		while (game->map[game->i][game->j])
		{
			if (game->map[game->i][game->j] == 'E')
				e++;
			else if (game->map[game->i][game->j] == 'C')
				game->c++;
			else if (game->map[game->i][game->j] == 'P')
			{
				p++;
				game->i_p = game->i;
				game->j_p = game->j;
			}
			game->j++;
		}
		game->i++;
	}
	if (p == 1 && game->c > 0 && e > 0)
		return (1);
	else
		return (0);
}

t_var	check_map(char **av)
{
	char	*join;
	t_var	game;
	int		i;

	i = 0;
	join = ft_read(av);
	game.map = ft_split(join, '\n');
	free(join);
	if (!game.map)
		ft_free(game.map, "Erorr : split\n");
	game.i = 0;
	game.c = 0;
	if (!check_line(game.map) || !check_car_1(game.map)
		|| !check_car_2(&game, 0, 0))
		ft_free(game.map, "Erorr : map failer\n");
	return (game);
}

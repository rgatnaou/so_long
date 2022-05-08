/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:41:50 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/29 13:18:13 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# define KEY_W 13
# define KEY_D 2
# define KEY_A 0
# define KEY_S 1
# define KEY_ESC 53

typedef struct s_var {
	void	*mlx;
	void	*win;
	char	**map;
	int		img_w;
	int		img_h;
	void	*mlx_coin1;
	void	*mlx_coin2;
	void	*mlx_coin4;
	void	*mlx_coin3;
	void	*mlx_coin5;
	void	*mlx_coin6;
	void	*mlx_wall;
	void	*mlx_player;
	void	*mlx_player1;
	void	*mlx_enemy;
	void	*mlx_exit;
	void	*mlx_space;
	int		i;
	int		move;
	int		j;
	int		c;
	int		i_p;
	int		j_p;
}	t_var;

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strnchar(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_free(char **map, char *str);
t_var	check_map(char **av);
int		key_hook(int keycode, t_var *game);
void	draw_bonus(t_var *game);
char	*ft_itoa(int n);

#endif
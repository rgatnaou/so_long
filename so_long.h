/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 20:04:26 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/23 23:22:49 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
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
	void	*mlx_coin;
	void	*mlx_wall;
	void	*mlx_player;
	void	*mlx_anima;
	void	*mlx_exit;
	void	*mlx_space;
	int		i;
	int		move;
	int		j;
	int		n;
	int		i_p;
	int		j_p;
	int		i_e;
	int		j_e;
}	t_var;

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strnchar(char *s1,char *s2);
char	*ft_get_line(char *left_str);
char	**ft_split(char const *s, char c);
void	ft_erorr(char *str);
void	ft_free(char **map);
t_var	check_map(int ac, char **av);
int		key_hook(int keycode, t_var *game);
void	draw(t_var *game);
char	*ft_itoa(int n);
#endif
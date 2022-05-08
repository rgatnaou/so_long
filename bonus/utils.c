/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:55:31 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/29 12:05:02 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strnchar(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	len -= 4;
	while (s1[len])
	{
		if (s1[len++] != s2[i++])
			return (1);
	}
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0' && c != '\0' )
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	len = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (0);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

void	ft_free(char **map, char *str)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	if (str)
		write(2, str, ft_strlen(str));
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 21:41:50 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/19 21:47:33 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define  BUFFER_SIZE 1

char	*get_line(char *res)
{
	char	*rtn;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!res[len])
		return (NULL);
	while (res[len] && res[len] != '\n')
		len++;
	if (res[len] == '\n' )
		len++;
	rtn = (char *)malloc(len + 1);
	if (!rtn)
		return (0);
	while (len)
	{
		rtn[i] = res[i];
		len--;
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*update_res(char *res)
{
	char	*rtn;
	int		len;
	int		l;
	int		i;

	len = 0;
	i = 0;
	while (res[len] && res[len] != '\n')
		len++;
	if (!res[len])
	{
		free(res);
		return (NULL);
	}
	len++;
	l = ft_strlen(&res[len]);
	rtn = (char *)malloc(l + 1);
	if (!rtn)
		return (0);
	while (l--)
		rtn[i++] = res[len++];
	rtn[i] = '\0';
	free(res);
	return (rtn);
}

char	*get_next_line_read(int fd, char *res)
{
	int			r_rd;
	char		*rd;

	rd = malloc(BUFFER_SIZE + 1);
	if (!rd)
		return (0);
	r_rd = 1;
	while (!ft_strchr(res, '\n') && r_rd)
	{
		r_rd = read(fd, rd, BUFFER_SIZE);
		if (r_rd == -1)
		{
			free(rd);
			return (NULL);
		}
		rd[r_rd] = '\0';
		res = ft_strjoin(res, rd);
	}
	free(rd);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*rtn;
	static char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = get_next_line_read(fd, res);
	if (!res)
		return (NULL);
	rtn = get_line(res);
	res = update_res(res);
	return (rtn);
}

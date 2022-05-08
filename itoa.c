/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:18:36 by rgatnaou          #+#    #+#             */
/*   Updated: 2022/04/26 22:19:07 by rgatnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*s;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	s = (char *)malloc(sizeof(s1[i]) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static int	ft_strln(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		i++;
	while (nb / 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	ft_st(long nb, char *ito, int i)
{
	while (nb)
	{
		i--;
		ito[i] = (nb % 10) + 48;
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*ito;
	int		ln;

	nb = n;
	if (!nb)
		return (ft_strdup("0"));
	ln = ft_strln(n);
	ito = (char *)malloc(sizeof(char) * (ln + 1));
	if (!ito)
		return (NULL);
	if (nb < 0)
	{
		ito[0] = '-';
		nb = nb * -1;
	}
	ft_st(nb, ito, ln);
	ito[ln] = 0;
	return (ito);
}

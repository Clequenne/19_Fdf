/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 17:45:38 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:22:37 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_size_nbr(long long int n)
{
	long long int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_fill_nbr(char *str, long long int n, int len)
{
	int	start;

	str[len] = '\0';
	len = len - 1;
	if (n < 0)
	{
		n = n * -1;
		start = 1;
		str[0] = '-';
	}
	else
		start = 0;
	while (len >= start)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len = len - 1;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	long long int	len2;

	len2 = n;
	len = ft_size_nbr(len2);
	if (len2 < 0)
		len = len + 1;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str = ft_fill_nbr(str, len2, len);
	return (str);
}

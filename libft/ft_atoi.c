/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:31:21 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:19:34 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	int i;
	int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 0;
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\n') ||
			(str[i] == '\r') || (str[i] == '\f') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb *= 10;
		nb += (str[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-nb);
	return (nb);
}

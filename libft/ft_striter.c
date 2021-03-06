/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 22:41:23 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:36:29 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int	i;

	if (s && f)
	{
		i = 0;
		while (s[i] != 0)
		{
			f(&s[i]);
			i++;
		}
	}
}

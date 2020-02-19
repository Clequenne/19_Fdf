/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 22:39:41 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:20:15 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_count_word(const char *s, char c)
{
	size_t	i;
	int		nb_w;
	int		new_w;

	if (!s || !c)
		return (0);
	i = 0;
	nb_w = 0;
	new_w = 1;
	while (s[i])
	{
		if (new_w && s[i] != c)
		{
			nb_w++;
			new_w = 0;
		}
		if (s[i] == c)
			new_w = 1;
		i++;
	}
	return (nb_w);
}

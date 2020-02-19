/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:09:41 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:27:46 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_print_word(const char *s, char c, size_t *start)
{
	size_t	c1;

	if (!s || !c || !start)
		return (NULL);
	while (s[*start] == c)
		*start += 1;
	c1 = *start;
	while (s[*start])
	{
		if (s[*start] == c)
			break ;
		*start += 1;
	}
	return (ft_strsub(s, c1, *start - c1));
}

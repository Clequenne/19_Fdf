/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:40:59 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:37:31 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*fresh;

	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	fresh = (char *)malloc(sizeof(*fresh) * (len));
	i = 0;
	if (fresh)
	{
		while (*s1)
			fresh[i++] = *s1++;
		while (*s2)
			fresh[i++] = *s2++;
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:59:14 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:38:15 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char			*fresh;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		fresh = ft_strnew(ft_strlen(s));
		if (!fresh)
			return (NULL);
		i = 0;
		while (s[i])
		{
			fresh[i] = f(s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	else
		return (NULL);
}

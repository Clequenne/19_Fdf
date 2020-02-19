/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 22:46:41 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:47:04 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>

char	*ft_strstr(const char *big, const char *lit)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (lit[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		while (big[i] != lit[0])
		{
			i++;
			if (big[i] == '\0')
				return (NULL);
		}
		while (big[i + j] == lit[j] && lit[j] != '\0')
		{
			j++;
		}
		if (j == ft_strlen(lit))
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 22:30:35 by hponcin           #+#    #+#             */
/*   Updated: 2018/11/09 00:46:52 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int		ft_count_word(const char *s, char c)
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

static	char	*ft_print_word(const char *s, char c, size_t *start)
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

char			**ft_strsplit(char const *s, char c)
{
	int		nb_w;
	char	**split;
	size_t	i;
	size_t	start;

	nb_w = ft_count_word(s, c);
	if (!(split = (char **)malloc(sizeof(char*) * (nb_w + 1))) || !s || !c)
		return (NULL);
	i = 0;
	start = 0;
	while (nb_w--)
	{
		split[i] = ft_print_word(s, c, &start);
		i++;
	}
	split[i] = NULL;
	return (split);
}

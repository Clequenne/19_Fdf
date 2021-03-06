/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 00:25:14 by hponcin           #+#    #+#             */
/*   Updated: 2019/08/06 00:25:18 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "error_message.h"
#include <stdlib.h>

static void			free_strsplit_arr(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static t_coord_val	*new_coord(char *s)
{
	t_coord_val	*coord;
	char		**parts;

	if (!(coord = (t_coord_val *)ft_memalloc(sizeof(t_coord_val))))
		terminate(ERR_MAP_READING);
	if (!(parts = ft_strsplit(s, ',')))
		terminate(ERR_MAP_READING);
	if (!ft_isnumber(parts[0], 10))
		terminate(ERR_MAP_READING);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		terminate(ERR_MAP_READING);
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord->next = NULL;
	free_strsplit_arr(parts);
	return (coord);
}

static void			parse_line(char **coords_line,
							t_coord_val **coords_stack,
							t_map *map)
{
	int	width;

	width = 0;
	while (*coords_line)
	{
		push(coords_stack, new_coord(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		terminate(ERR_MAP);
}

int					read_map(const int fd,
							t_coord_val **coords_stack,
							t_map *map)
{
	char	*line;
	int		result;
	char	**coords_line;

	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(coords_line = ft_strsplit(line, ' ')))
			terminate(ERR_MAP_READING);
		parse_line(coords_line, coords_stack, map);
		free_strsplit_arr(coords_line);
		ft_strdel(&line);
		map->height++;
	}
	if (!(*coords_stack))
		terminate(ERR_MAP);
	return (result);
}

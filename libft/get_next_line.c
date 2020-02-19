/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:23:18 by hponcin           #+#    #+#             */
/*   Updated: 2019/08/06 19:36:18 by hponcin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/libft.h"
#include <unistd.h>

int		stock_line(int fd, char **save, char **line, int ret)
{
	char	*tmp;
	int		i;

	i = 0;
	while (save[fd][i] != '\n' && save[fd][i] != '\0')
		i++;
	if (save[fd][i] == '\n')
	{
		*line = ft_strsub(save[fd], 0, i);
		tmp = ft_strdup(save[fd] + i + 1);
		free(save[fd]);
		save[fd] = tmp;
	}
	else if (save[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(save[fd]);
		ft_strdel(&save[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strnew(BUFF_SIZE);
		tmp = ft_strjoin(save[fd], buf);
		free(save[fd]);
		save[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (save[fd] == NULL || save[fd][0] == '\0'))
		return (0);
	return (stock_line(fd, save, line, ret));
}

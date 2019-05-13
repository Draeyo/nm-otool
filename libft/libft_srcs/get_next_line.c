/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:07:52 by vlistrat          #+#    #+#             */
/*   Updated: 2016/01/07 17:51:39 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_join(char *s1, char *s2)
{
	size_t		a;
	size_t		b;
	char		*c;

	a = 0;
	b = 0;
	if (s1)
		a = ft_strlen(s1);
	if (s2)
		b = ft_strlen(s2);
	c = (char*)malloc(sizeof(*c) * (a + b + 1));
	if (a)
		ft_memcpy(c, s1, a);
	if (b)
		ft_memcpy(c + a, s2, b);
	c[a + b] = '\0';
	free(s1);
	ft_bzero(s2, BUFF_SIZE + 1);
	return (c);
}

static int		end_of_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
	{
		str[i] = '\0';
		return (i);
	}
	else
		return (-1);
}

static int		ft_verif(char **save, char **buf, char **line)
{
	char	*pnt_free;
	int		end;

	*save = ft_join(*save, *buf);
	end = end_of_line(*save);
	if (end > -1)
	{
		*line = ft_strdup(*save);
		pnt_free = *save;
		*save = ft_strdup(*save + end + 1);
		free(pnt_free);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*save[256];
	char			*buf;
	int				a;
	int				ret;

	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || (ret = read(fd, buf, 0)) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		a = ft_verif(&save[fd], &buf, line);
		free(buf);
		if (a == 1)
			return (1);
		buf = ft_strnew(BUFF_SIZE);
	}
	if ((a = ft_verif(&save[fd], &buf, line)))
		return (1);
	else if (ft_strlen(save[fd]) > 0)
	{
		*line = ft_strdup(save[fd]);
		ft_strdel(&save[fd]);
		return (1);
	}
	return (a);
}

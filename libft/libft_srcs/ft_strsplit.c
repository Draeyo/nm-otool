/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:41:03 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 14:27:55 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int		ft_start(char *str, char c, unsigned int i)
{
	while (str[i] == c && str[i] != '\0')
		i++;
	return (i);
}

static size_t			ft_end(char *str, char c, unsigned int start)
{
	size_t		i;

	i = start;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (i++);
		i++;
	}
	return (i);
}

static int				ft_words_nb(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			i = ft_start(str, c, i);
		else if (str[i] != c)
		{
			i = ft_end(str, c, i);
			j++;
		}
	}
	return (j);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**ret;
	int				i;
	unsigned int	start;
	size_t			end;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char*)s;
	start = ft_start(str, c, i);
	end = ft_end(str, c, start);
	if (!(ret = (char**)malloc(sizeof(*ret) * (ft_words_nb(str, c) + 1))))
		return (NULL);
	while (i < ft_words_nb(str, c) && start < ft_strlen(str))
	{
		ret[i] = ft_strsub(str, start, end - (size_t)start);
		start = ft_start(str, c, end);
		end = ft_end(str, c, start);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:17:20 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 14:00:01 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*strbuf;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	strbuf = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		strbuf[i] = f(s[i]);
		i++;
	}
	return (strbuf);
}

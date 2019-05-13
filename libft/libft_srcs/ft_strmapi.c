/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:09:30 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 14:01:53 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strbuf;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	strbuf = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		strbuf[i] = f(i, (char)s[i]);
		i++;
	}
	return (strbuf);
}

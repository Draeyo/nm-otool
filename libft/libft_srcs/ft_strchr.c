/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:59:32 by vlistrat          #+#    #+#             */
/*   Updated: 2015/11/30 19:56:48 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*sbuf;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	sbuf = (char*)s;
	if ((unsigned char)c == '\0')
		return (&sbuf[len]);
	while (sbuf[i])
	{
		if (sbuf[i] == (unsigned char)c)
			return (&sbuf[i]);
		i++;
	}
	return (NULL);
}

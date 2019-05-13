/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:32:56 by vlistrat          #+#    #+#             */
/*   Updated: 2015/11/30 20:02:22 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*sbuf;

	sbuf = (char*)s;
	i = ft_strlen(sbuf);
	if ((unsigned char)c == '\0')
		return (&sbuf[i]);
	i--;
	while (sbuf[i])
	{
		if (sbuf[i] == (unsigned char)c)
			return (&sbuf[i]);
		i--;
	}
	return (NULL);
}

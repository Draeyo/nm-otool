/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:30:28 by vlistrat          #+#    #+#             */
/*   Updated: 2015/11/28 18:09:44 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sbuf;

	if (s == NULL)
		return (NULL);
	sbuf = (unsigned char*)s;
	while (n > 0)
	{
		if (*sbuf == (unsigned char)c)
			return ((void*)sbuf);
		sbuf++;
		n--;
	}
	return (NULL);
}

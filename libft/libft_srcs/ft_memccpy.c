/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:34:38 by vlistrat          #+#    #+#             */
/*   Updated: 2015/11/26 12:34:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*srcbuf;
	char	*dstbuf;

	srcbuf = (char*)src;
	dstbuf = (char*)dst;
	while (n > 0 && *srcbuf != c)
	{
		n--;
		*dstbuf++ = *srcbuf++;
	}
	if (n > 0)
	{
		*dstbuf++ = *srcbuf++;
		return ((void*)dstbuf);
	}
	return (NULL);
}

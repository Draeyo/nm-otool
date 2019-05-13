/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:33:10 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 20:39:26 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcbuf;
	char	*dstbuf;

	srcbuf = (char*)src;
	dstbuf = (char*)dst;
	if (srcbuf < dstbuf)
	{
		dstbuf = dstbuf + len - 1;
		srcbuf = srcbuf + len - 1;
		while (len > 0)
		{
			*dstbuf-- = *srcbuf--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*dstbuf++ = *srcbuf++;
			len--;
		}
	}
	return (dst);
}

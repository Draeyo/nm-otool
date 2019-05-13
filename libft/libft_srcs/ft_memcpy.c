/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:21:38 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 13:28:25 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*srcbuf;
	unsigned char	*dstbuf;

	srcbuf = (unsigned char*)src;
	dstbuf = (unsigned char*)dst;
	i = 0;
	while (n--)
	{
		dstbuf[i] = srcbuf[i];
		i++;
	}
	return (dst);
}

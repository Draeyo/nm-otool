/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:27:34 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 20:40:47 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*bufs1;
	unsigned char	*bufs2;

	i = 0;
	bufs1 = (unsigned char *)s1;
	bufs2 = (unsigned char *)s2;
	while (i < n)
	{
		if (bufs1[i] != bufs2[i])
			return (bufs1[i] - bufs2[i]);
		i++;
	}
	return (0);
}

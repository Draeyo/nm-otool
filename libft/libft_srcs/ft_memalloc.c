/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:28:04 by vlistrat          #+#    #+#             */
/*   Updated: 2015/11/30 14:31:18 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dest;

	if (size <= 0)
		return (NULL);
	dest = malloc(size);
	if (dest == NULL)
		return (NULL);
	ft_memset(dest, 0, size);
	if (dest)
		return (dest);
	else
		return (NULL);
}

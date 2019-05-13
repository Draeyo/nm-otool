/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:57:37 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 14:20:54 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*copie;
	int		i;

	i = 0;
	if (s)
	{
		if (!(copie = ft_strnew(len)))
			return (NULL);
		while (len-- > 0)
			copie[i++] = (char)s[start++];
		return (copie);
	}
	return (NULL);
}

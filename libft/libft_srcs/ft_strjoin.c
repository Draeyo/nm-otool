/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:21:56 by vlistrat          #+#    #+#             */
/*   Updated: 2016/09/20 10:28:46 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	char		*copie;
	size_t		len;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return ((char*)s2);
	else if (!s2)
		return ((char*)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	copie = ft_strnew(len + 1);
	while (*s1)
	{
		copie[i] = (char)*s1++;
		i++;
	}
	while (*s2)
	{
		copie[i] = (char)*s2++;
		i++;
	}
	return (copie);
}

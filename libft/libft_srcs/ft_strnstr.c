/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:09:47 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 20:57:28 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find(char *str1, char *str2, size_t i, size_t n)
{
	size_t		j;
	int			k;

	k = 0;
	while (str1[i] && i < n)
	{
		j = 0;
		if (str1[i] == str2[j])
		{
			k = (int)i;
			while (str2[j] && str1[i] == str2[j] && i < n)
			{
				if (j == ft_strlen(str2) - 1)
					return (k);
				i++;
				j++;
			}
			if (str2[j] == '\0')
				return (k);
			i = (size_t)k;
		}
		i++;
	}
	return (-1);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		k;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	if (s2[i] == '\0')
		return (str1);
	k = ft_find(str1, str2, i, n);
	if (k >= 0)
		return (&str1[k]);
	return (NULL);
}

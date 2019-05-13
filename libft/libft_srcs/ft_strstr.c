/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:27:44 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 19:44:49 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find(char *str1, char *str2, int i)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (str1[i])
	{
		j = 0;
		if (str1[i] == str2[j])
		{
			k = i;
			while (str2[j] && str1[i] == str2[j])
			{
				i++;
				j++;
			}
			if (j == (int)ft_strlen(str2))
				return (k);
			else
				i = k;
		}
		i++;
	}
	return (-1);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		k;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	if (str2[i] == '\0')
		return (str1);
	k = ft_find(str1, str2, i);
	if (k != -1)
		return (&str1[k]);
	return (NULL);
}

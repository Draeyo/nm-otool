/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:53:36 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/10 17:08:12 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcut(char *str, int n)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strnew(ft_strlen(str) + n);
	while (str[i] && i < n)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

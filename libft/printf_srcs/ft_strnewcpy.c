/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:17:59 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/17 17:18:06 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnewcpy(char *str)
{
	char	*ret;
	int		i;

	ret = ft_strnew((int)ft_strlen(str));
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

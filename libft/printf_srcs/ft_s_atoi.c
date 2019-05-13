/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:11:18 by vlistrat          #+#    #+#             */
/*   Updated: 2016/09/12 15:26:06 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s_atoi(char *str)
{
	int		ret;
	int		mult;
	int		i;

	i = ft_strlen(str) - 1;
	mult = 1;
	ret = 0;
	while (i > -1 && ft_isdigit(str[i]))
	{
		ret += ((str[i] - 48) * mult);
		mult *= 10;
		i--;
	}
	if (str[i] == '-')
		ret *= -1;
	return (ret);
}

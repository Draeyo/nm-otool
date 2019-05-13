/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/21 14:15:42 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		ft_itoo(uintmax_t nb)
{
	uintmax_t		ret;
	uintmax_t		mult;

	ret = 0;
	mult = 1;
	if (nb == 0)
		return (0);
	while (nb)
	{
		ret += nb % 8 * mult;
		mult *= 10;
		nb /= 8;
	}
	return (ret);
}

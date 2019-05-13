/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:30:14 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/23 12:30:59 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	calc_div(int len)
{
	uintmax_t	div;

	div = 1;
	while (--len)
		div *= 10;
	return (div);
}

char				*ft_uxtoa(uintmax_t nb)
{
	uintmax_t	div;
	char		*ret;
	int			len;
	int			i;

	i = 0;
	len = ft_uxnblen(nb);
	div = calc_div(len);
	ret = ft_strnew(len + 1);
	if (nb == 0)
		return ("0");
	while (len-- && div)
	{
		ret[i] = ((nb / div) + 48);
		nb -= ((nb / div) * div);
		div /= 10;
		i++;
	}
	return (ret);
}

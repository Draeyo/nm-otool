/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:19:17 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 11:52:01 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_conv_p(va_list ap, t_print *lst)
{
	char			*str;
	unsigned long	p;

	str = NULL;
	p = va_arg(ap, unsigned long);
	HEX = "0x";
	if (!ZEROP)
	{
		str = ft_itohex(p);
		return (ft_padding_str(lst, str));
	}
	return (ft_padding_str(lst, ""));
}

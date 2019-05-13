/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:58:15 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 14:26:22 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_padding_int(t_print *lst, intmax_t nb)
{
	int		ret;

	ret = 0;
	if (nb < 0)
	{
		nb *= -1;
		if ((PREC && PREC >= WIDTH) || ft_strchr(FLAG, '0'))
		{
			MIN = 1;
			ret += ft_putstr("-");
		}
		NEG = 1;
	}
	if (nb == 0)
		return (ft_padding_str(lst, "0"));
	STR = ft_xtoa(nb);
	ret += ft_padding_str(lst, STR);
	return (ret);
}

int		ft_padding_uint(t_print *lst, uintmax_t nb)
{
	int		ret;

	ret = 0;
	if (nb == 0)
		return (ft_padding_str(lst, "0"));
	STR = ft_uxtoa(nb);
	ret += ft_padding_str(lst, STR);
	return (ret);
}

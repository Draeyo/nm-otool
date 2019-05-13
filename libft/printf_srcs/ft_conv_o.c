/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:26:46 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 13:39:34 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzo(va_list ap, t_print *lst)
{
	uintmax_t	jo;
	size_t		zo;

	jo = 0;
	zo = 0;
	if (MODIF && ft_strstr(MODIF, "j"))
	{
		jo = va_arg(ap, uintmax_t);
		STR = ft_uitooa(jo);
		return (ft_padding_str(lst, STR));
	}
	else if (MODIF && ft_strstr(MODIF, "z"))
	{
		zo = va_arg(ap, size_t);
		STR = ft_uitooa(zo);
		return (ft_padding_str(lst, STR));
	}
	return (-1);
}

static int		ft_conv_ho(va_list ap, t_print *lst)
{
	unsigned char	hho;
	unsigned short	ho;

	hho = 0;
	ho = 0;
	if (MODIF && ft_strstr(MODIF, "hh"))
	{
		hho = va_arg(ap, unsigned int);
		return (ft_padding_uint(lst, ft_itoo(hho)));
	}
	else if (MODIF && ft_strstr(MODIF, "h"))
	{
		ho = va_arg(ap, unsigned int);
		return (ft_padding_uint(lst, ft_itoo(ho)));
	}
	return (-1);
}

static int		ft_conv_lo(va_list ap, t_print *lst)
{
	unsigned long long	llo;
	unsigned long		lo;

	llo = 0;
	lo = 0;
	if (MODIF && ft_strstr(MODIF, "ll"))
	{
		llo = va_arg(ap, unsigned long long);
		STR = ft_uitooa(llo);
		return (ft_padding_str(lst, STR));
	}
	else if ((MODIF && ft_strstr(MODIF, "l")) || CONV == 'O')
	{
		lo = va_arg(ap, unsigned long);
		if (lo == 0 && ZEROP)
			return (ft_padding_str(lst, ""));
		STR = ft_uitooa(lo);
		return (ft_padding_str(lst, STR));
	}
	return (-1);
}

int				ft_conv_o(va_list ap, t_print *lst)
{
	unsigned int	o;
	int				count;

	o = 0;
	count = 0;
	if (!MODIF && CONV == 'o')
	{
		o = va_arg(ap, unsigned int);
		if (o == 0 && ZEROP)
			return (ft_padding_str(lst, ""));
		STR = ft_uitooa(o);
		return (ft_padding_str(lst, STR));
	}
	else if ((count = ft_conv_lo(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_ho(ap, lst)) > 0)
		return (count);
	else if ((count = ft_conv_jzo(ap, lst)) > 0)
		return (count);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:15:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 13:33:55 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzx(va_list ap, t_print *lst)
{
	uintmax_t	jx;
	size_t		zx;

	jx = 0;
	zx = 0;
	if (MODIF && ft_strstr(MODIF, "j"))
	{
		jx = va_arg(ap, uintmax_t);
		STR = ft_itohex(jx);
		return (ft_padding_str(lst, STR));
	}
	else if (MODIF && ft_strstr(MODIF, "z"))
	{
		zx = va_arg(ap, size_t);
		STR = ft_itohex(zx);
		return (ft_padding_str(lst, STR));
	}
	return (-1);
}

static int		ft_conv_hx(va_list ap, t_print *lst)
{
	unsigned char	hhx;
	unsigned short	hx;

	hhx = 0;
	hx = 0;
	if (MODIF && ft_strstr(MODIF, "hh"))
	{
		hhx = va_arg(ap, unsigned int);
		STR = ft_itohex(hhx);
		return (ft_padding_str(lst, STR));
	}
	else if (MODIF && ft_strstr(MODIF, "h"))
	{
		hx = va_arg(ap, unsigned int);
		STR = ft_itohex(hx);
		return (ft_padding_str(lst, STR));
	}
	return (-1);
}

static int		ft_conv_lx(va_list ap, t_print *lst)
{
	unsigned long long	llx;
	unsigned long		lx;

	llx = 0;
	lx = 0;
	if (MODIF && ft_strstr(MODIF, "ll"))
	{
		llx = va_arg(ap, unsigned long long);
		STR = ft_itohex(llx);
		return (ft_padding_str(lst, STR));
	}
	else if (MODIF && ft_strstr(MODIF, "l"))
	{
		lx = va_arg(ap, unsigned long);
		STR = ft_itohex(lx);
		return (ft_padding_str(lst, STR));
	}
	return (-1);
}

int				ft_conv_x(va_list ap, t_print *lst)
{
	unsigned int	x;

	x = 0;
	if (ft_strchr(FLAG, '#') && CONV == 'x')
		lst->hex = "0x";
	else if (ft_strchr(FLAG, '#') && CONV == 'X')
		lst->hex = "0X";
	if (!MODIF && (CONV == 'x' || CONV == 'X'))
	{
		x = va_arg(ap, unsigned int);
		if (x == 0 && ZEROP)
		{
			HEX = "";
			return (ft_padding_str(lst, ""));
		}
		STR = ft_itohex(x);
		return (ft_padding_str(lst, STR));
	}
	else if ((COUNT = ft_conv_hx(ap, lst)) > 0)
		return (COUNT);
	else if ((COUNT = ft_conv_lx(ap, lst)) > 0)
		return (COUNT);
	else if ((COUNT = ft_conv_jzx(ap, lst)) > 0)
		return (COUNT);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:17:55 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 13:49:42 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_jzd(va_list ap, t_print *lst)
{
	intmax_t	jd;
	long long	zd;

	jd = 0;
	zd = 0;
	if (MODIF && ft_strstr(MODIF, "j"))
	{
		jd = va_arg(ap, intmax_t);
		return (ft_padding_int(lst, jd));
	}
	else if (MODIF && ft_strstr(MODIF, "z"))
	{
		zd = va_arg(ap, long long);
		return (ft_padding_int(lst, zd));
	}
	return (-1);
}

static int		ft_conv_hd(va_list ap, t_print *lst)
{
	char		c;
	short		s;

	if (MODIF && ft_strstr(MODIF, "hh"))
	{
		c = va_arg(ap, int);
		return (ft_padding_int(lst, (int)c));
	}
	else if (MODIF && ft_strstr(MODIF, "h"))
	{
		s = va_arg(ap, int);
		return (ft_padding_int(lst, s));
	}
	return (-1);
}

static int		ft_conv_ld(va_list ap, t_print *lst)
{
	long		ld;
	long long	lld;

	ld = 0;
	lld = 0;
	if (MODIF && ft_strstr(MODIF, "ll"))
	{
		lld = va_arg(ap, long long);
		return (ft_padding_int(lst, lld));
	}
	else if ((MODIF && ft_strstr(MODIF, "l")) || CONV == 'D')
	{
		ld = va_arg(ap, long);
		return (ft_padding_int(lst, ld));
	}
	return (-1);
}

int				ft_conv_d(va_list ap, t_print *lst)
{
	int				d;
	unsigned int	ud;

	d = 0;
	ud = 0;
	if (!MODIF && (CONV == 'd' || CONV == 'i'))
	{
		d = va_arg(ap, int);
		if (d == 0 && ZEROP)
			return (ft_padding_str(lst, ""));
		return (ft_padding_int(lst, d));
	}
	if ((COUNT = ft_conv_ld(ap, lst)) > 0)
		return (COUNT);
	else if ((COUNT = ft_conv_hd(ap, lst)) > 0)
		return (COUNT);
	else if ((COUNT = ft_conv_jzd(ap, lst)) > 0)
		return (COUNT);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:58:48 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 14:15:39 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_ws(va_list ap, t_print *lst)
{
	if ((CONV == 'S') || (MODIF && ft_strstr(MODIF, "l") && CONV == 's'))
		WSTR = va_arg(ap, wchar_t*);
	if (WSTR)
	{
		LEN = ft_wstrlen(WSTR);
		return (ft_padding_str(lst, ""));
	}
	else
	{
		LEN = 6;
		return (ft_padding_str(lst, "(null)"));
	}
	return (0);
}

int		ft_conv_wc(va_list ap, t_print *lst)
{
	wint_t		wint;

	wint = 0;
	if ((CONV == 'C') || (MODIF && ft_strstr(MODIF, "l") && CONV == 'c'))
		wint = va_arg(ap, wint_t);
	WC = wint;
	LEN = 1;
	if (wint == 0)
		return (ft_putwchar_fd(WC, 1));
	return (ft_padding_str(lst, ""));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:27:45 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/29 15:15:06 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_s(va_list ap, t_print *lst)
{
	int		ret;
	char	*s;

	s = NULL;
	ret = 0;
	if (CONV == 's')
	{
		s = va_arg(ap, char*);
		if (ZEROP)
			ret = ft_padding_str(lst, "");
		else if (s == NULL)
			ret = ft_padding_str(lst, "(null)");
		else
			ret = ft_padding_str(lst, s);
	}
	else if ((MODIF && ft_strstr(MODIF, "l")) || CONV == 'S')
		return (ft_conv_ws(ap, lst));
	return (ret);
}

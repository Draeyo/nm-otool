/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:40:06 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 16:19:03 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_c(va_list ap, t_print *lst)
{
	char	c;
	int		a;

	c = 0;
	a = 0;
	if ((MODIF && ft_strstr(MODIF, "l") && CONV == 'c') || CONV == 'C')
		return (ft_conv_wc(ap, lst));
	else if (!MODIF && CONV == 'c')
	{
		c = va_arg(ap, int);
		return (ft_padding_str(lst, &c));
	}
	return (0);
}

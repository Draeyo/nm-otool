/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:22:42 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 14:38:35 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			i;
	int			j;
	va_list		ap;
	t_print		*lst;

	i = 0;
	j = 0;
	lst = (t_print*)malloc(sizeof(*lst));
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += ft_conv_tag(&format[i], lst);
			j += ft_tag(ap, lst);
		}
		else
		{
			j += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(ap);
	free(lst);
	return (j);
}

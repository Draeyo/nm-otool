/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 12:28:09 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 14:36:55 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_tag(va_list ap, t_print *lst)
{
	int		j;

	j = 0;
	if (lst->conv == '%')
		j = ft_noconv(lst);
	else if (lst->conv == 's' || lst->conv == 'S')
		j = ft_conv_s(ap, lst);
	else if (lst->conv == 'd' || lst->conv == 'i' || lst->conv == 'D')
		j = ft_conv_d(ap, lst);
	else if (lst->conv == 'x' || lst->conv == 'X')
		j = ft_conv_x(ap, lst);
	else if (lst->conv == 'c' || lst->conv == 'C')
		j = ft_conv_c(ap, lst);
	else if (lst->conv == 'o' || lst->conv == 'O')
		j = ft_conv_o(ap, lst);
	else if (lst->conv == 'p')
		j = ft_conv_p(ap, lst);
	else if (lst->conv == 'u' || lst->conv == 'U')
		j = ft_conv_u(ap, lst);
	free_all(lst);
	return (j);
}

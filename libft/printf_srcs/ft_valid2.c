/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 13:21:53 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/16 17:01:24 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_after_prec(int c)
{
	if (!ft_ismod(c) && !ft_isconv(c))
		return (0);
	return (1);
}

int		ft_plus(t_print *lst)
{
	if (lst->conv == 'd' || lst->conv == 'D' || lst->conv == 'i')
		return (1);
	return (0);
}

int		ft_ishex(t_print *lst)
{
	if (lst->conv == 'x' || lst->conv == 'X')
		return (1);
	return (0);
}

int		ft_is_c(t_print *lst)
{
	if (lst->conv == 's' || lst->conv == 'S' || lst->conv == 'c' ||
			lst->conv == 'C' || lst->conv == '%')
		return (1);
	return (0);
}

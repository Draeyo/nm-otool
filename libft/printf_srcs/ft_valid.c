/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:59:01 by vlistrat          #+#    #+#             */
/*   Updated: 2016/02/17 17:18:40 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isconv(int c)
{
	if ((char)c == 's' || (char)c == 'S' || (char)c == 'p'
			|| (char)c == 'd' || (char)c == 'D' || (char)c == 'i'
			|| (char)c == 'o' || (char)c == 'O' || (char)c == 'u'
			|| (char)c == 'U' || (char)c == 'x' || (char)c == 'X'
			|| (char)c == 'c' || (char)c == 'C' || (char)c == '%')
		return (1);
	return (0);
}

int		ft_ismod(int c)
{
	if ((char)c == 'h' || (char)c == 'l' || (char)c == 'j' || (char)c == 'z')
		return (1);
	return (0);
}

int		ft_validmod(char *str)
{
	if (str[0] == 'h' && str[1] == 'h' && str[2] == '\0')
		return (1);
	else if (str[0] == 'l' && str[1] == 'l' && str[2] == '\0')
		return (1);
	else if ((str[0] == 'h' || str[0] == 'l' || str[0] == 'j' || str[0] == 'z')
			&& str[1] == '\0')
		return (1);
	return (0);
}

int		ft_after_flag(int c)
{
	if (!ft_isdigit(c) && (char)c != '.' && !ft_ismod(c) && !ft_isconv(c))
		return (0);
	return (1);
}

int		ft_after_width(int c)
{
	if ((char)c != '.' && !ft_ismod(c) && !ft_isconv(c))
		return (0);
	return (1);
}

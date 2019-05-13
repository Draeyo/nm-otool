/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:15:25 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/31 09:39:39 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_tag_error(t_print *lst, const char *format)
{
	int		i;

	i = 0;
	CONV = '0';
	TAG = NULL;
	while (format[i] != ' ')
		i++;
	return (++i);
}

int		ft_zeroflag(t_print *lst)
{
	char	c;

	c = CONV;
	if (((c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
			|| c == 'D' || c == 'O' || c == 'U') && lst->prec > 0)
			|| lst->conv == 's')
		return (0);
	return (1);
}

int		ft_zprec(t_print *lst, char *tag, int i)
{
	if (tag[i] != '.')
		return (0);
	else if (tag[i] == '.' && (tag[i + 1] == '0' || ft_after_prec(tag[i + 1])))
	{
		if (tag[i + 1] == '0')
		{
			ZEROP = 1;
			return (-3);
		}
		else if (ft_after_prec(tag[i + 1]))
		{
			ZEROP = 1;
			return (-1);
		}
	}
	return (1);
}

void	ft_short_padneg(t_print *lst)
{
	LEN++;
	PREC++;
}

int		ft_spstr_min(t_print *lst)
{
	if ((!PREC && !ft_strchr(FLAG, '0')) && ft_plus(lst) && NEG == 1 && !MIN)
		return (1);
	return (0);
}

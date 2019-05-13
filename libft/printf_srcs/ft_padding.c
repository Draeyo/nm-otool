/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:09:39 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/30 14:28:38 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_short_hex(t_print *lst)
{
	PREC -= 2;
	return (ft_strjoin(HEX, ft_strnew_digit(WIDTH, ZEROF)));
}

char			*ft_strnew_digit(int nb, int fill)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * (nb + 1));
	while (nb--)
	{
		str[i] = fill;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_width(t_print *lst, int len)
{
	int		i;

	if (CONV == 'S' && WSTR)
		len = ft_wstrlen(WSTR);
	if ((ft_strchr(FLAG, '+') || ft_strchr(FLAG, ' ')) && WIDTH > len
			&& ft_plus(lst) && NEG == 0)
		WIDTH--;
	i = 0;
	if (PREC < len && !ft_is_c(lst) && !ft_strchr(FLAG, '-'))
		PREC = 0;
	if (PREC > WIDTH)
		return (NULL);
	if (PREC && len > 0 && ((!ft_strchr(FLAG, '-') && CONV != 's')
				|| (CONV == 's' && len > PREC)))
		WIDTH -= PREC;
	else if ((WIDTH -= len) <= 0)
		return (NULL);
	if (ft_strchr(FLAG, '-') && CONV != 's')
		WIDTH -= PREC;
	if (!(WDT = ft_strnew_digit(WIDTH, ZEROF)))
		return (NULL);
	if (ft_ishex(lst) && ft_strchr(FLAG, '0') && !ft_strchr(FLAG, '-'))
		return (ft_short_hex(lst));
	return (WDT);
}

char			*ft_prec(t_print *lst, int len)
{
	int		i;

	i = 0;
	if (CONV == 'c' || CONV == 'C' || CONV == '%')
		return (NULL);
	if (CONV == 'p' && PREC > len)
		PREC += 2;
	if ((PREC -= len) <= 0)
		return (NULL);
	PRC = ft_strnew_digit(PREC, '0');
	return (PRC);
}

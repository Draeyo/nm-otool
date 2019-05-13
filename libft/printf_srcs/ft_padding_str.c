/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 14:26:16 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/31 09:17:43 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flags(t_print *lst)
{
	if (FLAG && !NEG && ft_strchr(FLAG, '+') && ft_plus(lst))
		return (ft_putstr("+"));
	else if (FLAG && !NEG && ft_strchr(FLAG, ' ') && ft_plus(lst))
		return (ft_putstr(" "));
	return (0);
}

static char		*ft_diese_o(t_print *lst, char *str)
{
	if ((CONV == 'O' || CONV == 'o') && ft_strchr(FLAG, '#') && str[0] != '0')
		str = ft_strjoin("0", str);
	return (str);
}

static int		ft_diese_x(t_print *lst, char *str)
{
	if (ft_ishex(lst))
	{
		if (!ft_strstr(str, "0") && ft_strchr(FLAG, '#')
				&& (!ft_strchr(FLAG, '0') || (ft_strchr(FLAG, '0')
						&& ft_strchr(FLAG, '-'))))
		{
			PREC -= 2;
			return (ft_putstr(HEX));
		}
	}
	else if (CONV == 'p')
		return (ft_putstr(HEX));
	else if ((PREC && PREC < WIDTH) && ft_plus(lst) && NEG == 1 && !MIN)
	{
		MIN = 1;
		return (ft_putstr("-"));
	}
	return (0);
}

static int		ft_short_pstr(t_print *lst, char *str, int ret)
{
	if (ft_strchr(FLAG, '0'))
		ret += ft_flags(lst);
	if (!ft_strchr(FLAG, '-'))
		ret += ft_putstr(ft_width(lst, LEN));
	if (!ft_strchr(FLAG, '0'))
		ret += ft_flags(lst);
	ret += ft_diese_x(lst, str);
	if (CONV != 's' && CONV != 'S')
		ret += ft_putstr(ft_prec(lst, LEN));
	if (PREC < 0)
		PREC = 0;
	if (CONV == 'X')
		str = ft_xupper(str);
	ret = ft_print(lst, str, ret);
	return (ret);
}

int				ft_padding_str(t_print *lst, char *str)
{
	int		ret;

	ret = 0;
	if (ft_zeroflag(lst) && ft_strchr(FLAG, '0') && !ft_strchr(FLAG, '-'))
		ZEROF = '0';
	else if ((CONV == 's' || CONV == 'S') && ft_strchr(FLAG, '0')
			&& !ft_strchr(FLAG, '-'))
		ZEROF = '0';
	if (CONV == 'o' || CONV == 'O')
		str = ft_diese_o(lst, str);
	if (CONV != 'S' && CONV != 'C')
		LEN = (int)ft_strlen(str);
	if (CONV == 'c')
		LEN = 1;
	if ((CONV == 's' || CONV == 'S') && PREC > LEN)
		PREC = 0;
	if (((CONV == 'x' || CONV == 'X') && ft_strchr(FLAG, '#')) || CONV == 'p')
		LEN += 2;
	else if (NEG == 1)
		ft_short_padneg(lst);
	ret += ft_short_pstr(lst, str, ret);
	if (ft_strchr(FLAG, '-'))
		ret += ft_putstr(ft_width(lst, LEN));
	return (ret);
}

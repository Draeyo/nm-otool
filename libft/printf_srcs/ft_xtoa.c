/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:31:46 by vlistrat          #+#    #+#             */
/*   Updated: 2016/11/08 10:53:11 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		calc_len(intmax_t nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	else if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char		*ret_zero(char *ret)
{
	ret[0] = '0';
	return (ret);
}

char			*get_alpha(char *ret, uintmax_t n, char *stock, int i)
{
	while (n)
	{
		ret[i] = stock[n % 10];
		n /= 10;
		i--;
	}
	return (ret);
}

char			*ft_xtoa(intmax_t nb)
{
	uintmax_t	n;
	char		*ret;
	char		*stock;
	int			i;
	int			neg;

	i = calc_len(nb) - 1;
	neg = 0;
	ret = ft_strnew(i + 1);
	stock = "0123456789";
	if (nb < 0)
	{
		neg = 1;
		n = (uintmax_t)nb * -1;
	}
	else if (nb == 0)
		return (ret_zero(ret));
	else
		n = (uintmax_t)nb;
	ret = get_alpha(ret, n, stock, i);
	if (neg)
		ret[i] = '-';
	return (ret);
}

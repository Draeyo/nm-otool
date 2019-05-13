/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_tag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:14:16 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/31 09:59:27 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			lst_init(t_print *lst)
{
	lst->tag = NULL;
	lst->flag = NULL;
	lst->width = 0;
	lst->prec = 0;
	lst->modif = NULL;
	lst->conv = '\0';
	lst->len = 0;
	lst->neg = 0;
	lst->hex = NULL;
	lst->zeroflag = ' ';
	lst->zeroprec = 0;
	lst->count = 0;
	lst->str = NULL;
	lst->wstr = NULL;
	lst->wc = 0;
	lst->min = 0;
	lst->wdt = NULL;
	lst->prc = NULL;
}

static int		ft_short_ctag(t_print *lst, int k)
{
	int		ret;

	ret = ft_get_prec(TAG + k, lst);
	if (ret == -3)
		k += 2;
	else if (ret < -1)
		return (-1);
	else if (ret == -1)
		k++;
	else if (ret > 0)
		k += ft_nblen(PREC) + 1;
	if (ft_get_modif(TAG + k, lst) < 0)
		return (-1);
	else if (MODIF)
		k += ft_strlen(MODIF);
	if (ft_get_conv(TAG + k, lst) < 0)
		return (-1);
	else
		k++;
	return (k);
}

int				ft_conv_tag(const char *format, t_print *lst)
{
	int		k;
	int		ret;

	k = 0;
	ret = 0;
	lst_init(lst);
	if (!(TAG = ft_get_tag(&format[1], ft_get_last(&format[1], 0))))
		return (1);
	if (ft_get_flag(TAG + k, lst) < 0)
		return (ft_tag_error(lst, format));
	else
		k += (int)ft_strlen(FLAG);
	ret = ft_get_width(TAG + k, lst);
	if (ret < -1)
		return (ft_tag_error(lst, format));
	else if (ret > -1)
		k += ft_nblen(WIDTH);
	if ((ret = ft_short_ctag(lst, k)) == -1)
		return (ft_tag_error(lst, format));
	else
		k += ret;
	LEN = ft_strlen(TAG) + 1;
	return (LEN);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:47:55 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 21:07:36 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_char(const char c)
{
	if (c == '-' || c == '+' || c == ',' || c == '\200')
		return (1);
	if (c == ' ' || c == '\n' || c == '\t')
		return (2);
	if (c == '\r' || c == '\f' || c == '\v')
		return (2);
	return (0);
}

static int		skip_space(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && is_char(str[i]) >= 1)
		i++;
	if (i > 1 && is_char(str[i]) == 2)
		i--;
	if (is_char(str[i]) == 1 && ft_isdigit((int)str[i + 1]) == 1)
		i++;
	while (str[i] && ft_isdigit((int)str[i]) == 1)
		i++;
	if (i > 0)
		i--;
	if (ft_isalpha(str[i]) == 1)
		i--;
	return (i);
}

int				ft_atoi(const char *str)
{
	int		i;
	int		mult;
	int		ret;

	if (!str)
		return (0);
	else if (skip_space(str) < 0)
		return (0);
	i = skip_space(str);
	ret = 0;
	mult = 1;
	while (str[i] && is_char(str[i]) == 0 && i >= 0)
	{
		ret += ((str[i] - 48) * mult);
		mult *= 10;
		i--;
	}
	if (is_char(str[i]) >= 1 && is_char(str[i - 1]) == 1)
		return (0);
	else if (str[i] == '-' && ret > 0)
		ret *= -1;
	else if (str[i] == '\200')
		return (0);
	return (ret);
}

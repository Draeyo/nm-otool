/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:31:00 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/02 19:28:50 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int		ft_div(unsigned int nb)
{
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (nb > 10)
	{
		nb /= 10;
		i++;
	}
	while (i > 0)
	{
		ret *= 10;
		i--;
	}
	return (ret);
}

static int		ft_size_alloc(unsigned int nb)
{
	int		i;

	i = 1;
	if (ft_isneg(nb) == 1)
		i++;
	if (nb > 0)
	{
		while ((nb / 10) > 0)
		{
			nb /= 10;
			i++;
		}
		return (i);
	}
	return (i);
}

static char		*ft_fill(char *ret, unsigned int nb, int div, int i)
{
	while (div > 0)
	{
		ret[i] = ((nb / div) + '0');
		nb -= (div * (nb / div));
		div /= 10;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char			*ft_itoa(int n)
{
	char			*ret;
	int				i;
	int				div;
	unsigned int	nb;
	int				neg;

	neg = ft_isneg(n);
	i = 0;
	div = 0;
	if (neg == 1)
	{
		n *= -1;
		i++;
	}
	nb = (unsigned int)n;
	ret = (char*)malloc(sizeof(*ret) * ft_size_alloc(nb) + 1);
	if (ret == NULL)
		return (NULL);
	if (neg == 1)
		ret[0] = '-';
	div = ft_div(nb);
	ret = ft_fill(ret, nb, div, i);
	return (ret);
}

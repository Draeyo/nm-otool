/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:08:34 by vlistrat          #+#    #+#             */
/*   Updated: 2016/08/23 14:24:19 by vlistrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*content_copie;
	size_t	size_copie;

	content_copie = NULL;
	size_copie = content_size;
	if (content == NULL)
	{
		content_copie = NULL;
		size_copie = 0;
	}
	else
	{
		ft_memcpy(content_copie, content, ft_strlen(content));
		content_copie = (void*)content;
		size_copie = content_size;
	}
	new = (t_list*)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	new->content = content_copie;
	new->content_size = size_copie;
	new->next = NULL;
	return (new);
}

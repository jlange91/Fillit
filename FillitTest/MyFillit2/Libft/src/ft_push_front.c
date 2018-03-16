/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:22:26 by jlange            #+#    #+#             */
/*   Updated: 2016/11/11 17:04:47 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push_front(t_list **list, void *content, size_t content_size)
{
	t_list	*tmp;

	tmp = *list;
	if (tmp)
	{
		tmp = ft_create_elem(content, content_size);
		tmp->next = *list;
		*list = tmp;
	}
	else
		tmp = ft_create_elem(content, content_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:55:16 by jlange            #+#    #+#             */
/*   Updated: 2016/11/16 15:46:01 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long	ft_top_left(unsigned long i)
{
	i = ft_max_left(i);
	i = ft_max_up(i);
	return (i);
}

unsigned long	ft_max_left(unsigned long i)
{
	while ((i & ~ft_vertical_mask(1)) == 0)
		i >>= 1;
	return (i);
}

unsigned long	ft_max_right(unsigned long i)
{
	while ((i & ft_vertical_mask(7)) == 0)
		i <<= 1;
	return (i);
}

unsigned long	ft_max_up(unsigned long i)
{
	while ((i & ~ft_horizontal_mask(1)) == 0)
		i >>= 8;
	return (i);
}

unsigned long	ft_max_down(unsigned long i)
{
	while ((i & ft_horizontal_mask(7)) == 0)
		i <<= 8;
	return (i);
}

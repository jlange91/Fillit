/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:34:32 by jlange            #+#    #+#             */
/*   Updated: 2016/11/30 23:48:24 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long	ft_horizontal_mask(int x)
{
	unsigned long	mask;
	unsigned long	unite;
	int				count;
	int				i;

	mask = 0;
	unite = 1;
	count = 0;
	i = -1;
	while (++i < x)
		count += 16;
	while (x < 4)
	{
		i = -1;
		while (++i < 16)
		{
			mask = mask | (unite << count);
			count++;
		}
		x++;
	}
	return (mask);
}

unsigned long	ft_vertical_mask(int x)
{
	unsigned long	mask;
	unsigned long	unite;
	int				count;
	int				i;

	mask = 0;
	unite = 1;
	unite <<= x;
	count = 0;
	while (x < 16)
	{
		i = -1;
		while (++i < 16)
		{
			mask = mask | (unite << count);
			count += 16;
		}
		unite <<= 1;
		x++;
	}
	return (mask);
}

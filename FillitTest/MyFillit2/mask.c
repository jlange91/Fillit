/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:34:32 by jlange            #+#    #+#             */
/*   Updated: 2016/11/24 12:20:16 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_init_mask(t_mask *mask)
{
	mask->vertical_l = ~ft_vertical_mask(4);
	mask->vertical_r = ft_vertical_mask(4);
	mask->horizontal_u = ~ft_horizontal_mask(4);
	mask->horizontal_d = ft_horizontal_mask(4);
	mask->top_left = ~ft_horizontal_mask(4) & ~ft_vertical_mask(4);
	mask->top_right = ~ft_horizontal_mask(4) & ft_vertical_mask(4);
	mask->bottom_left = ft_horizontal_mask(4) & ~ft_vertical_mask(4);
	mask->bottom_right = ft_horizontal_mask(4) & ft_vertical_mask(4);
	mask->up = ~ft_horizontal_mask(1);
	mask->down = ft_horizontal_mask(7);
	mask->left = ~ft_vertical_mask(1);
	mask->right = ft_vertical_mask(7);
}

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
	while (x < 16)
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

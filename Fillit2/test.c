/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:14:01 by jlange            #+#    #+#             */
/*   Updated: 2016/11/24 13:02:31 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_bits(unsigned long nb)
{
	int count;

	count = 0;
	while (count < 64)
	{
		if (nb % 2 == 0)
			ft_putchar('.');
		else
			ft_putchar('#');
		count++;
		if (count % 16 == 0)
		{
			ft_putchar('\n');
		}
		nb = nb / 2;
	}
}

void	ft_print_bits_map(short nb)
{
	int count;

	count = 0;
	while (count < 16)
	{
		if (nb % 2 == 0)
			ft_putchar('.');
		else
			ft_putchar('#');
		count++;
		nb = nb / 2;
	}
}

void	ft_print_tetri(t_tetri *tetri)
{
	printf("id : %d x : %d y : %d width : %d length : %d\ntetri :\n", tetri->id, tetri->x, tetri->y, tetri->width, tetri->length);
	ft_print_bits(tetri->tetriminos);ft_putchar('\n');
}

void	print_map(t_map map)
{
	int i;

	i = 0;
	printf("max_size : %d min_size : %d size : %d nb_tetri : %d\n", map.max_size, map.min_size, map.size, map.nb_tetri);
	while (i < 16)
	{
		ft_print_bits_map(map.map[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_list(t_tetri *tetri)
{
	while (tetri)
	{
		ft_print_tetri(tetri);
		tetri = tetri->next;
	}
}

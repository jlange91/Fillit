/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:14:01 by jlange            #+#    #+#             */
/*   Updated: 2016/11/23 21:52:02 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_bits(int i)
{
	while (i > 0)
	{
		if (i % 2 == 0)
			ft_putchar('0');
		else
			ft_putchar('1');
		i = i / 2;
	}
}

void	ft_print_tetri(t_tetri *tetri)
{
	printf("id : %d x : %d y : %d width : %d length : %d\ntetri :\n", tetri->id, tetri->x, tetri->y, tetri->width, tetri->length);
	ft_print_bits(tetri->tetriminos[0]);ft_putchar('\n');
	ft_print_bits(tetri->tetriminos[1]);ft_putchar('\n');
	ft_print_bits(tetri->tetriminos[2]);ft_putchar('\n');
	ft_print_bits(tetri->tetriminos[3]);ft_putstr("\n\n");
}

void	print_map(t_map map)
{
	int i;

	i = 0;
	printf("max_size : %d min_size : %d size : %d nb_tetri : %d\n", map.max_size, map.min_size, map.size, map.nb_tetri);
	while (i < 32)
	{
		ft_print_bits(map.map[i]);
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

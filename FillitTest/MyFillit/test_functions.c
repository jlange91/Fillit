/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 04:27:52 by jlange            #+#    #+#             */
/*   Updated: 2016/11/17 21:17:32 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_bits(unsigned long nb)
{
	int count;

	count = 0;
	while (nb > 0)
	{
		if (nb % 2 == 0)
			ft_putchar('0');
		else
			ft_putchar('1');
		count++;
		if (count == 8)
		{
			ft_putchar('\n');
			count = 0;
		}
		nb = nb / 2;
	}
}

#define T_TETRI ((t_tetri *)list->content)
void	ft_test_list(t_list *list)
{
	while (list)
	{
		ft_print_bits(((t_tetri *)list->content)->tetriminos);
		printf("\n\nunsigned long = %lu\nid = %d\nwidth = %d\nlength = %d\nx = %d\ny = %d\nmap = %d\n\n", T_TETRI->tetriminos, T_TETRI->id, T_TETRI->width, T_TETRI->length, T_TETRI->x, T_TETRI->y, T_TETRI->map);
		list = list->next;
	}
}

void	ft_display_map_info(t_map map)
{
	printf("\nmap 1 : %lu  map 2 : %lu\nmap 3 : %lu  map 4 : %lu\nmax_size : %d\nmin_size : %d\nsize : %d\nnb_tetri : %d\n\n", map.map[0], map.map[1], map.map[2], map.map[3], map.max_size, map.min_size, map.size, map.nb_tetri);
}

void	ft_display_mask(t_mask mask)
{
	printf("\nvertical_l =\n%lu\n\n", mask.vertical_l);
	ft_print_bits(mask.vertical_l);
	printf("\nvertical_r =\n%lu\n\n", mask.vertical_r);
	ft_print_bits(mask.vertical_r);
	printf("\nhorizontal_u =\n%lu\n\n", mask.horizontal_u);
	ft_print_bits(mask.horizontal_u);
	printf("\nhorizontal_d =\n%lu\n\n", mask.horizontal_d);
	ft_print_bits(mask.horizontal_d);
	printf("\ntop_left =\n%lu\n\n", mask.top_left);
	ft_print_bits(mask.top_left);
	printf("\ntop_right =\n%lu\n\n", mask.top_right);
	ft_print_bits(mask.top_right);
	printf("\nbottom_left =\n%lu\n\n", mask.bottom_left);
	ft_print_bits(mask.bottom_left);
	printf("\nbottom_right =\n%lu\n\n", mask.bottom_right);
	ft_print_bits(mask.bottom_right);
	printf("\nup =\n%lu\n\n", mask.up);
	ft_print_bits(mask.up);
	printf("\ndown =\n%lu\n\n", mask.down);
	ft_print_bits(mask.down);
	printf("\nleft =\n%lu\n\n", mask.left);
	ft_print_bits(mask.left);
	printf("\nright =\n%lu\n\n", mask.right);
	ft_print_bits(mask.right);
	printf("\n\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:19:23 by jlange            #+#    #+#             */
/*   Updated: 2016/11/30 22:18:18 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define ID ft_putstr("map :");ft_putnbr(TETRI_MAP);ft_putstr(" id :");ft_putnbr(((t_tetri *)tetri->content)->id);ft_putstr("\n");
int		ft_decale_tetri(t_list *tetri, t_map *map)
{
	if (TETRI_X + TETRI_WIDTH < map->size)
	{
		TETRI_X++;
		TETRI <<= 1;
		return (1);
	}
	else if (TETRI_Y + TETRI_LENGTH < map->size)
	{
		TETRI_Y++;
		TETRI_X = 0;
		TETRI <<= 8;
		return (1);
}
#define TEST ft_print_bits(TETRI);ft_putstr("\n\n");char c; read(0, &c, 1);
int		ft_put_tetri(t_list *tetri, t_map *map, t_mask mask)
{
	t_tetri tmp;

	tmp = save_tetri(tetri);
//	ID TEST
	ft_create_map(tetri, map, mask);
	while ((TETRI & MAP(TETRI_MAP)) != 0)
	{
		if (!ft_decale_tetri(tetri, map))
		{
			tmp_tetri(tetri,tmp);
			return (0);
		}
//		TEST
	}
	ft_update_map(tetri, map, mask);
	return (1);
}

void		ft_solve(t_list *tetri,t_map *map, t_mask mask)
{
	while (tetri)
	{
		if (ft_put_tetri(tetri, map, mask))
		{
			map->ret = 1;
			ft_solve(tetri->next,map, mask);
		}
		else
		{
			map->ret = 0;
			return ;
		}
		if (map->ret == 0)
		{
			ft_create_map(tetri,map,mask);
			ft_update_map(tetri, map, mask);
			reset_tetri(tetri->next);
			if (!ft_decale_tetri(tetri,map))
			{
				reset_tetri(tetri);
				return ;
			}
			continue ;
		}
		return ;
	}
}

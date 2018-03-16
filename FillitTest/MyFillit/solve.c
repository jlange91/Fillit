/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:19:23 by jlange            #+#    #+#             */
/*   Updated: 2016/11/24 10:58:59 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_map(t_list *tetri)
{
	if (TETRI_X + TETRI_WIDTH < 9 && TETRI_Y + TETRI_LENGTH < 9)
		TETRI_MAP = 0;
	else if (TETRI_X + TETRI_WIDTH < 13 && TETRI_Y + TETRI_LENGTH < 9)
		TETRI_MAP = 1;
	else if (TETRI_X + TETRI_WIDTH > 12 && TETRI_Y + TETRI_LENGTH < 9)
		TETRI_MAP = 2;
	else if (TETRI_X + TETRI_WIDTH < 9 && TETRI_Y + TETRI_LENGTH < 13)
		TETRI_MAP = 3;
	else if (TETRI_X + TETRI_WIDTH < 13 && TETRI_Y + TETRI_LENGTH < 13)
		TETRI_MAP = 4;
	else if (TETRI_X + TETRI_WIDTH > 12 && TETRI_Y + TETRI_LENGTH < 13)
		TETRI_MAP = 5;
	else if (TETRI_X + TETRI_WIDTH < 9 && TETRI_Y + TETRI_LENGTH > 12)
		TETRI_MAP = 6;
	else if (TETRI_X + TETRI_WIDTH < 13 && TETRI_Y + TETRI_LENGTH > 12)
		TETRI_MAP = 7;
	else if (TETRI_X + TETRI_WIDTH > 12 && TETRI_Y + TETRI_LENGTH > 12)
		TETRI_MAP = 8;
}

void	ft_create_map(t_map *map, t_mask mask)
{
		MAP(1) = 0;
		MAP(1) = (mask.vertical_r & MAP(0)) >> 4;
		MAP(1) = MAP(1) | (mask.vertical_l & MAP(2)) << 4;

		MAP(3) = 0;
		MAP(3) = (mask.horizontal_d & MAP(0)) >> 32;
		MAP(3) = MAP(3) | ((mask.horizontal_u & MAP(6)) << 32);

		MAP(4) = 0;
		MAP(4) = (mask.bottom_right & MAP(0)) >> 36;
		MAP(4) = MAP(4) | ((mask.bottom_left & MAP(2)) >> 28);
		MAP(4) = MAP(4) | ((mask.top_right & MAP(6)) << 28);
		MAP(4) = MAP(4) | ((mask.top_left & MAP(8)) << 36);

		MAP(5) = 0;
		MAP(5) = (mask.horizontal_d & MAP(2)) >> 32;
		MAP(5) = MAP(5) | ((mask.horizontal_u & MAP(8)) << 32);

		MAP(7) = 0;
		MAP(7) = (mask.vertical_r & MAP(6)) >> 4;
		MAP(7) = MAP(7) | ((mask.vertical_l & MAP(8)) << 4);
}

void	ft_update_map(t_list *tetri, t_map *map, t_mask mask)
{
		MAP(0) = MAP(0) | ((mask.vertical_l & MAP(1)) << 4);
		MAP(2) = MAP(2) | ((mask.vertical_r & MAP(1)) >> 4);

		MAP(0) = MAP(0) | ((mask.horizontal_u & MAP(3)) << 32);
		MAP(6) = MAP(6) | ((mask.horizontal_d & MAP(3)) >> 32);

		MAP(0) = MAP(0) | ((mask.top_left & MAP(4)) << 36);
		MAP(2) = MAP(2) | ((mask.top_right & MAP(4)) << 28);
		MAP(6) = MAP(6) | ((mask.bottom_left & MAP(4)) >> 28);
		MAP(8) = MAP(8) | ((mask.bottom_right & MAP(4)) >> 36);

		MAP(2) = MAP(2) | ((mask.horizontal_u & MAP(5)) << 32);
		MAP(8) = MAP(8) | ((mask.horizontal_u & MAP(5)) >> 32);

		MAP(6) = MAP(6) | ((mask.vertical_l & MAP(7)) << 4);
		MAP(8) = MAP(8) | ((mask.vertical_r & MAP(7)) >> 4);
		MAP(1) = 0;
		MAP(3) = 0;
		MAP(4) = 0;
		MAP(5) = 0;
		MAP(7) = 0;

}
#define TEST ft_print_bits(TETRI);ft_putstr("\n\n");read(0, &c, 1);
#define ID ft_putstr("x :");ft_putnbr(TETRI_X);ft_putstr(" y :");ft_putnbr(TETRI_Y); ft_putstr(" map :");ft_putnbr(TETRI_MAP);ft_putstr(" id :");ft_putnbr(((t_tetri *)tetri->content)->id);ft_putstr("\n");
int		ft_decale_tetri(t_list *tetri, t_map *map)
{char c;
	if (TETRI_X + TETRI_WIDTH < map->size)
	{
		TETRI_X++;
		ft_map(tetri);
		if (TETRI_X + TETRI_WIDTH - 1 == 8 || TETRI_X + TETRI_WIDTH - 1 == 12)
			TETRI >>= 3;
		else
			TETRI <<= 1;
		return (1);
	}
	else if (TETRI_Y + TETRI_LENGTH < map->size)
	{
		if (TETRI_X + TETRI_WIDTH - 1 > 7)
			TETRI >>= TETRI_X - 4;
		else if (TETRI_X + TETRI_WIDTH > 11)
			TETRI >>= TETRI_X - 8;
		else
			TETRI >>= TETRI_X;
		TETRI_Y++;
		TETRI_X = 0;
		ft_map(tetri);
		if (TETRI_Y + TETRI_LENGTH - 1 == 8 || TETRI_Y + TETRI_LENGTH - 1 == 12)
			TETRI >>= 24;
		else
			TETRI <<= 8;
		return (1);
	}
	else
		return(0);
}
int		ft_put_tetri(t_list *tetri, t_map *map, t_mask mask)
{
	t_tetri tmp;

	tmp = save_tetri(tetri);
	ft_create_map(map, mask);
	while ((TETRI & MAP(TETRI_MAP)) != 0)
	{
		if (!ft_decale_tetri(tetri, map))
		{
			tmp_tetri(tetri,tmp);
			return (0);
		}
	}
		MAP(TETRI_MAP) = TETRI ^ MAP(TETRI_MAP);
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
			ft_create_map(map,mask);
			MAP(TETRI_MAP) = TETRI ^ MAP(TETRI_MAP);
			ft_update_map(tetri, map, mask);
			reset_tetri(tetri->next);
			if (!ft_decale_tetri(tetri,map))
			{
				reset_tetri(tetri->next);
				return ;
			}
			continue ;
		}
		return ;
	}
	map->ret = 1;
}

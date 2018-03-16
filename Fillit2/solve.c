/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:12:59 by jlange            #+#    #+#             */
/*   Updated: 2016/12/01 01:21:53 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline int		ft_decale_tetri(t_tetri *tetri, t_map *map)
{
	if (tetri->x + tetri->width < map->size)
	{
		tetri->tetriminos <<= 1;
		tetri->x++;
		return (1);
	}
	else if (tetri->y + tetri->length < map->size)
	{
		tetri->y++;
		tetri->tetriminos >>= map->size - tetri->width;
		tetri->x = 0;
		return (1);
	}
	return (0);
}

static inline int		ft_put_tetri(t_tetri *tetri, t_map *map)
{
	t_tmp tmp;

	tmp = save_tetri(tetri);
	while (((tetri->tetriminos & (*(unsigned long*)(map->map + tetri->y)))))
	{
		if (ft_decale_tetri(tetri, map) == 0)
		{
			tmp_tetri(tetri, tmp);
			return (0);
		}
	}
	*(unsigned long*)(map->map + tetri->y) ^= tetri->tetriminos;
	return (1);
}

void					ft_solve(t_tetri *tetri,t_map *map)
{
	while (tetri)
	{
		if (ft_put_tetri(tetri, map))
		{
			map->ret = 1;
			ft_solve(tetri->next, map);
		}
		else
		{
			map->ret = 0;
			return ;
		}
		if (map->ret == 0)
		{
			*(unsigned long*)(map->map + tetri->y) ^= tetri->tetriminos;
			ft_reset_tetri(tetri->next);
			if (!ft_decale_tetri(tetri, map))
			{
				ft_reset_tetri2(tetri);
				return ;
			}
			continue ;
		}
		return ;
	}
}

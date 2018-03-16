/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:12:59 by jlange            #+#    #+#             */
/*   Updated: 2016/11/24 15:55:30 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void	ft_put_or_remove(t_tetri *tetri, t_map *map)
{
	map->map[tetri->y] ^= tetri->tetriminos[0];
	map->map[tetri->y + 1] ^= tetri->tetriminos[1];
	map->map[tetri->y + 2] ^= tetri->tetriminos[2];
	map->map[tetri->y + 3] ^= tetri->tetriminos[3];
}

static inline int	ft_check_for_put(t_tetri *tetri, t_map *map)
{
	int ret;

	ret = 0;
	ret = ((tetri->tetriminos[0] & map->map[tetri->y]) == 0) ? ret : ret + 1;
	ret = ((tetri->tetriminos[1] & map->map[tetri->y + 1]) == 0) ? ret :
		ret + 1;
	ret = ((tetri->tetriminos[2] & map->map[tetri->y + 2]) == 0) ? ret :
		ret + 1;
	ret = ((tetri->tetriminos[3] & map->map[tetri->y + 3]) == 0) ? ret :
		ret + 1;
	if (tetri->x + tetri->width > map->size)
		ret++;
	else if (tetri->y + tetri->length > map->size)
		ret++;
	return (ret == 0) ? 1 : 0;
}

static inline int	ft_decale_tetri(t_tetri *tetri, t_map *map)
{
	if (tetri->x + tetri->width < map->size)
	{
		tetri->tetriminos[0] <<= 1;
		tetri->tetriminos[1] <<= 1;
		tetri->tetriminos[2] <<= 1;
		tetri->tetriminos[3] <<= 1;
		tetri->x++;
		return (1);
	}
	else if (tetri->y + tetri->length < map->size)
	{
		tetri->y++;
		tetri->tetriminos[0] >>= map->size - tetri->width;
		tetri->tetriminos[1] >>= map->size - tetri->width;
		tetri->tetriminos[2] >>= map->size - tetri->width;
		tetri->tetriminos[3] >>= map->size - tetri->width;
		tetri->x = 0;
		return (1);
	}
	return (0);
}

static inline int	ft_put_tetri(t_tetri *tetri, t_map *map)
{
	t_tmp tmp;

	tmp = save_tetri(tetri);
	while (ft_check_for_put(tetri, map) == 0)
	{
		if (ft_decale_tetri(tetri, map) == 0)
		{
			tmp_tetri(tetri, tmp);
			return (0);
		}
	}
	ft_put_or_remove(tetri, map);
	return (1);
}

void				ft_solve(t_tetri *tetri, t_map *map)
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
			ft_put_or_remove(tetri, map);
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

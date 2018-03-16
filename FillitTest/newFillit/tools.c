/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:25:56 by jlange            #+#    #+#             */
/*   Updated: 2016/11/23 18:51:50 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_top_left(t_tetri *tetri)
{
	while (tetri->tetriminos[0] == 0)
	{
		tetri->tetriminos[0] = tetri->tetriminos[1];
		tetri->tetriminos[1] = tetri->tetriminos[2];
		tetri->tetriminos[2] = tetri->tetriminos[3];
		tetri->tetriminos[3] = 0;
	}
	while (((tetri->tetriminos[0] & 1) == 0) &&
			((tetri->tetriminos[1] & 1) == 0) &&
			((tetri->tetriminos[2] & 1) == 0))
	{
		tetri->tetriminos[0] >>= 1;
		tetri->tetriminos[1] >>= 1;
		tetri->tetriminos[2] >>= 1;
		tetri->tetriminos[3] >>= 1;
	}
}

void	ft_init_map(t_map *map)
{
	int min;
	int max;
	int i;
	
	min = 1;
	max = 1;
	i = 0;
	while (min * min < 4 * map->nb_tetri)
		min++;
	map->min_size = min;
	while (max * max < 6 * map->nb_tetri)
		max++;
	map->max_size = max;
	map->size = min;
	while (i < 32)
	{
		map->map[i] = 0;
		i++;
	}
}

void	ft_reset_tetri(t_tetri *tetri)
{
	while (tetri)
	{
		tetri->x = 0;
		tetri->y = 0;
		ft_top_left(tetri);
		tetri = tetri->next;
	}
}

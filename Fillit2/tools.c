/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:25:56 by jlange            #+#    #+#             */
/*   Updated: 2016/11/24 12:51:48 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	while (i < 16)
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

t_tmp	save_tetri(t_tetri *tetri)
{
	t_tmp tmp;

	tmp.tetriminos = tetri->tetriminos;
	tmp.x = tetri->x;
	tmp.y = tetri->y;
	tmp.width = tetri->width;
	tmp.length = tetri->length;
	return (tmp);
}

void	tmp_tetri(t_tetri *tetri, t_tmp tmp)
{
	tetri->tetriminos = tmp.tetriminos;
	tetri->x = tmp.x;
	tetri->y = tmp.y;
	tetri->width = tmp.width;
	tetri->length = tmp.length;
}

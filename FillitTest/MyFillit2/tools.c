/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:30:53 by jlange            #+#    #+#             */
/*   Updated: 2016/11/16 19:31:48 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_find_min_max(t_map *map)
{
	int min;
	int max;
	
	min = 1;
	max = 1;
	while (min * min < 4 * map->nb_tetri)
		min++;
	map->min_size = min;
	while (max * max < 6 * map->nb_tetri)
		max++;
	map->max_size = max;
	map->size = min;
}

t_tetri	save_tetri(t_list *tetri)
{
	t_tetri tmp;

	tmp.tetriminos = TETRI;
	tmp.x = TETRI_X;
	tmp.y = TETRI_Y;
	tmp.width = TETRI_WIDTH;
	tmp.length = TETRI_LENGTH;
	tmp.map = TETRI_MAP;
	return (tmp);
}

void	tmp_tetri(t_list *tetri, t_tetri tmp)
{
	TETRI = tmp.tetriminos;
	TETRI_X = tmp.x;
	TETRI_Y = tmp.y;
	TETRI_WIDTH = tmp.width;
	TETRI_LENGTH = tmp.length;
	TETRI_MAP = tmp.map;
}

void	reset_tetri(t_list *tetri)
{
	while (tetri)
	{
		TETRI = ft_top_left(TETRI);
		TETRI_X = 0;
		TETRI_Y = 0;
		tetri = tetri->next;
	}
}

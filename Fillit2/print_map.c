/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:46:54 by jlange            #+#    #+#             */
/*   Updated: 2016/12/01 00:13:49 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline char	**init_print_map(t_tetri *tetri, t_map map)
{
	char **map_f;
	int i;
	int j;

	if (!(map_f = (char**)malloc(sizeof(char*) * map.size + 1)))
		return (NULL);
	while (tetri)
	{
		ft_top_left(tetri);
		tetri = tetri->next;
	}
	i = 0;
	while (i < map.size)
	{
		if (!(map_f[i] = (char*)malloc(sizeof(char) * map.size + 1)))
			return (NULL);
		j = -1;
		while (++j < map.size)
		{
			map_f[i][j] = '.';
		}
		map_f[i][j] = '\0';
		i++;
	}
	return (map_f);
}

static inline void	ft_print(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_map(t_tetri *tetri, t_map map)
{
	char	**map_f;
	int		x;
	int		y;

	map_f = init_print_map(tetri, map);

	while (tetri)
	{
		x = 0;
		y = 0;
		while (tetri->tetriminos)
		{
			if (tetri->tetriminos & 1)
			{
				map_f[tetri->y + y][tetri->x + x] = tetri->id + 65;
			}
			tetri->tetriminos >>= 1;
			x++;
			if (x == 16)
			{
				x = 0;
				y++;
			}
		}
		tetri = tetri->next;
	}
	ft_print(map_f);
}

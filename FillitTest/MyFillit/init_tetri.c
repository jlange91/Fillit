/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:07:17 by jlange            #+#    #+#             */
/*   Updated: 2016/11/16 15:46:55 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_init_tetri_size(t_list *tetri)
{
	while (tetri)
	{
		TETRI_WIDTH = 0;
		TETRI_LENGTH = 0;
		while ((TETRI & ft_vertical_mask(7)) == 0)
		{
			TETRI <<= 1;
			TETRI_WIDTH++;
		}
		TETRI_WIDTH = 8 - TETRI_WIDTH;
		while ((TETRI & ft_horizontal_mask(7)) == 0)
		{
			TETRI <<= 8;
			TETRI_LENGTH++;
		}
		TETRI_LENGTH = 8 - TETRI_LENGTH;
		TETRI = ft_max_left(TETRI);
		TETRI = ft_max_up(TETRI);
		tetri = tetri->next;
	}
}

void			ft_init_map(t_map *map)
{
	int i;

	i = 0;
	while (i < 9)
	{
		map->map[i] = 0;
		i++;
	}
	map->max_size = 0;
	map->min_size = 0;
	map->size = 0;
	map->nb_tetri = 0;
}

unsigned long	ft_fill_tetri(char *file)
{
	static int		i;
	int				count;
	unsigned long	tetri;
	unsigned long	unite;

	count = -1;
	tetri = 0;
	unite = 1;
	while (file[i])
	{
		while ((file[i] != '\n' || file[i + 1] != '\n') && file[i])
		{
			count = (file[i] == '.' || file[i] == '#') ? count + 1 : count;
			tetri = (file[i] == '#') ? tetri | (unite << count) : tetri;
			count = (file[i] == '\n') ? count + 4 : count;
			i++;
		}
		tetri = ft_top_left(tetri);
		i++;
		return (tetri);
	}
	return (0);
}

t_tetri			*ft_tetrinew(void)
{
	t_tetri		*tetri;

	if (!(tetri = malloc(sizeof(t_tetri))))
		return (NULL);
	tetri->id = 0;
	tetri->tetriminos = 0;
	tetri->x = 0;
	tetri->y = 0;
	tetri->map = 0;
	return (tetri);
}

t_list			*ft_fill(char *file, int *nb)
{
	t_list			*l_tetri;
	t_tetri			*s_tetri;
	unsigned long	tetri;
	int				i;

	i = 0;
	s_tetri = ft_tetrinew();
	s_tetri->id = ++i;
	s_tetri->tetriminos = ft_fill_tetri(file);
	l_tetri = ft_create_elem(s_tetri, sizeof(s_tetri));
	while ((tetri = ft_fill_tetri(file)) != 0)
	{
		s_tetri = ft_tetrinew();
		s_tetri->tetriminos = tetri;
		s_tetri->id = ++i;
		ft_push_back(&l_tetri, s_tetri, sizeof(s_tetri));
	}
	*nb = i;
	return (l_tetri);
}

/*
   0 0 0 0 1 1 1 1
   0 0 0 0 1 1 1 1
   0 0 0 0 1 1 1 1
   0 0 0 0 1 1 1 1
   0 0 0 0 1 1 1 1
   0 0 0 0 1 1 1 1
   0 0 0 0 1 1 1 1
   0 0 0 0 1 1 1 1

   0 0 0 0 0 0 0 0
   0 0 0 0 0 0 0 0
   0 0 0 0 0 0 0 0
   0 0 0 0 0 0 0 0
   1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1
   1 1 1 1 1 1 1 1

   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .
   ---------------------------------
   . . . . C C C C | D D D D . . . .
   . . . . C C C C | D D D D . . . .
   . . . . C C C C | D D D D . . . .
   . . . . C C C C | D D D D . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .

   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .
   . . . . . . . . | . . . . . . . .

   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .
   . . . . A A A A | B B B B . . . .

   A A A A B B B B
   A A A A B B B B
   A A A A B B B B
   A A A A B B B B
   C C C C D D D D
   C C C C D D D D
   C C C C D D D D
   C C C C D D D D
   ~ => non
   ^ => xor
   & => and
   | => or
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:10:36 by jlange            #+#    #+#             */
/*   Updated: 2016/11/30 23:59:05 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init_size_tetri(t_tetri *tetri)
{
	while (tetri)
	{
		tetri->width = 0;
		tetri->length = 0;
		while ((tetri->tetriminos & ft_vertical_mask(15)) == 0)
		{
			tetri->tetriminos <<= 1;
			tetri->width++;
		}
		tetri->width = 16 - tetri->width;
		while ((tetri->tetriminos & ft_horizontal_mask(3)) == 0)
		{
			tetri->tetriminos <<= 16;
			tetri->length++;
		}
		tetri->length = 4 - tetri->length;
		ft_max_left(tetri);
		ft_max_up(tetri);
		tetri = tetri->next;
	}
}

static void		ft_fill_tetri(t_tetri *tetri, char *file)
{
	static int		i;
	int				count;
	unsigned long	unite;

	count = -1;
	unite = 1;
	while (file[i])
	{
		while ((file[i] != '\n' || file[i + 1] != '\n') && file[i])
		{
			count = (file[i] == '.' || file[i] == '#') ? count + 1 : count;
			tetri->tetriminos = (file[i] == '#') ? tetri->tetriminos |
				(unite << count) : tetri->tetriminos;
			count = (file[i] == '\n') ? count + 12 : count;
			i++;
		}
		ft_top_left(tetri);
		i++;
		return ;
	}
}

void			ft_fill(t_tetri *tetri, char *file, t_map map)
{
	int i;

	i = 0;
	while (i < map.nb_tetri)
	{
		ft_fill_tetri(tetri, file);
	//	ft_init_size_tetri(tetri);
		tetri = tetri->next;
		i++;
	}
}

t_tetri			*ft_init_tetri(int i)
{
	t_tetri		*tetri;

	tetri = (t_tetri*)malloc(sizeof(t_tetri) * 1);
	tetri->id = i;
	tetri->tetriminos = 0;
	tetri->x = 0;
	tetri->y = 0;
	tetri->width = 0;
	tetri->length = 0;
	return (tetri);
}

t_tetri			*ft_create_tetri(t_map map)
{
	t_tetri		*tetri;
	t_tetri		*tmp;
	int			i;

	i = 0;
	tetri = ft_init_tetri(i);
	tmp = tetri;
	while (++i < map.nb_tetri)
	{
		tetri->next = ft_init_tetri(i);
		tetri = tetri->next;
	}
	tetri->next = NULL;
	return (tmp);
}

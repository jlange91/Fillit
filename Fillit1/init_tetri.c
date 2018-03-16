/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:10:36 by jlange            #+#    #+#             */
/*   Updated: 2016/11/23 19:18:53 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_init_size_tetri(t_tetri *tetri)
{
	int		count;

	count = 0;
	while (tetri->tetriminos[3] == 0)
	{
		tetri->tetriminos[3] = tetri->tetriminos[2];
		tetri->tetriminos[2] = tetri->tetriminos[1];
		tetri->tetriminos[1] = tetri->tetriminos[0];
		tetri->tetriminos[0] = 0;
		count++;
	}
	tetri->length = 4 - count;
	count = 0;
	while (((tetri->tetriminos[3] & 8) == 0) &&
			((tetri->tetriminos[2] & 8) == 0) &&
			((tetri->tetriminos[1] & 8) == 0))
	{
		tetri->tetriminos[3] = tetri->tetriminos[3] << 1;
		tetri->tetriminos[2] = tetri->tetriminos[2] << 1;
		tetri->tetriminos[1] = tetri->tetriminos[1] << 1;
		tetri->tetriminos[0] = tetri->tetriminos[0] << 1;
		count++;
	}
	tetri->width = 4 - count;
	ft_top_left(tetri);
}

static void		ft_fill_tetri(t_tetri *tetri, char *file)
{
	static int	i;
	int			unite;
	int			count;
	int			j;

	unite = 1;
	count = -1;
	j = 0;
	while (file[i])
	{
		while ((file[i] != '\n' || file[i + 1] != '\n') && file[i])
		{
			count = (file[i] == '.' || file[i] == '#') ? count + 1 : count;
			tetri->tetriminos[j] = (file[i] == '#') ? tetri->tetriminos[j] |
				(unite << count) : tetri->tetriminos[j];
			count = (file[i] == '\n') ? -1 : count;
			j = (file[i] == '\n') ? j + 1 : j;
			i++;
		}
		ft_top_left(tetri);
		i = i + 2;
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
		ft_init_size_tetri(tetri);
		tetri = tetri->next;
		i++;
	}
}

t_tetri			*ft_init_tetri(int i)
{
	t_tetri		*tetri;

	tetri = (t_tetri*)malloc(sizeof(t_tetri) * 1);
	tetri->id = i;
	tetri->tetriminos[0] = 0;
	tetri->tetriminos[1] = 0;
	tetri->tetriminos[2] = 0;
	tetri->tetriminos[3] = 0;
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

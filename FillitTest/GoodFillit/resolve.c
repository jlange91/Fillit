/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:57:48 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/20 19:21:30 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_it_once(int n, char **map, t_fillit *f, int p)
{
	(*map)[p + (*f).pos[0][0] * (n + 1) + (*f).pos[0][1]] = (*f).c;
	(*map)[p + (*f).pos[1][0] * (n + 1) + (*f).pos[1][1]] = (*f).c;
	(*map)[p + (*f).pos[2][0] * (n + 1) + (*f).pos[2][1]] = (*f).c;
	(*map)[p + (*f).pos[3][0] * (n + 1) + (*f).pos[3][1]] = (*f).c;
	(*f).p = p;
}

void	erase_it(int n, char **map, t_fillit *f, int p)
{
	(*map)[p + (*f).pos[0][0] * (n + 1) + (*f).pos[0][1]] = '.';
	(*map)[p + (*f).pos[1][0] * (n + 1) + (*f).pos[1][1]] = '.';
	(*map)[p + (*f).pos[2][0] * (n + 1) + (*f).pos[2][1]] = '.';
	(*map)[p + (*f).pos[3][0] * (n + 1) + (*f).pos[3][1]] = '.';
	(*f).p = -1;
}

void	display(int n, char *map)
{
	write(1, map, (n + 1) * n);
}

int		fill_it(char **map, t_fillit *f, t_info *l, int *p)
{
	while (*p + f->pos[3][0] * (l->min + 1) +
			f->pos[3][1] < (l->min + 1) * l->min)
	{
		(*p)++;
		if ((*map)[*p + f->pos[0][0] * (l->min + 1) + f->pos[0][1]] == '.' &&
				(*map)[*p + f->pos[1][0] * (l->min + 1) + f->pos[1][1]] == '.'
				&&
				(*map)[*p + f->pos[2][0] * (l->min + 1) + f->pos[2][1]] == '.'
				&&
				(*map)[*p + f->pos[3][0] * (l->min + 1) + f->pos[3][1]] == '.')
		{
			set_it_once(l->min, map, f, *p);
			return (1);
		}
	}
	return (0);
}

int		resolve(t_fillit **f, t_info *l, char **map)
{
	t_rec2 g;

	g.nb = 0;
	g.p = -1;
	g.max = l->n;
	while (g.nb != g.max)
	{
		if (fill_it(map, &((*f)[g.nb]), l, &g.p))
		{
			g.nb++;
			g.p = -1;
		}
		else
		{
			g.nb--;
			if (g.nb == -1)
				return (0);
			g.p = (*f)[g.nb].p;
			erase_it(l->min, map, &((*f)[g.nb]), g.p);
		}
	}
	display(l->min, *map);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thirdpart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:54:17 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/20 19:30:09 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_some(t_fillit **linear, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		(*linear)[i].p = -1;
		i++;
	}
}

void	min_map(t_info *l)
{
	int		t;

	t = 0;
	while (t * t < l->n * 4)
		t++;
	l->min = t;
}

char	*generate_map(int size)
{
	int		i;
	char	*map;

	i = 1;
	map = (char *)malloc(sizeof(char) * (size * size) + size);
	while (i < (size * size) + size)
	{
		if (i % (size + 1) == 0 && i != 0)
			map[i - 1] = '\n';
		else
			map[i - 1] = '.';
		i++;
	}
	map[i - 1] = '\n';
	map[i] = 0;
	return (map);
}

int		main(int argc, char **argv)
{
	t_fillit	*linear;
	t_info		l;
	char		*map;

	if (argc != 2)
	{
		write(1, "usage: ./fillit file\n", 21);
		return (0);
	}
	if (!check(argv[1]) || open(argv[1], O_RDONLY) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	linear = full_it(argv[1], &l);
	min_map(&l);
	map = generate_map(l.min);
	while (resolve(&linear, &l, &map) != 1)
	{
		l.min++;
		ft_strdel(&map);
		map = generate_map((&l)->min);
	}
	return (0);
}

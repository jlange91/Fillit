/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:08:56 by jlange            #+#    #+#             */
/*   Updated: 2016/11/24 14:53:50 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free(t_tetri **tetri)
{
	t_tetri *tmp;

	while (*tetri)
	{
		tmp = *tetri;
		*tetri = (*tetri)->next;
		free(tmp);
	}
}

void	ft_main2(int fd)
{
	char		*file;
	t_map		map;
	t_tetri		*tetri;

	if (!(file = ft_getfile(fd, &map)) ||
			!(ft_check_file(file)))
		ft_putstr("error\n");
	else
	{
		tetri = ft_create_tetri(map);
		ft_fill(tetri, file, map);
		ft_init_map(&map);
		map.ret = 1;
		ft_solve(tetri, &map);
		while (map.ret == 0)
		{
			map.size++;
			ft_solve(tetri, &map);
		}
		ft_print_map(tetri, map);
		ft_free(&tetri);
	}
}

int		main(int ac, char **av)
{
	int fd;

	fd = 0;
	if (ac != 2)
		ft_putstr("usage: ./fillit file\n");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) != -1)
		{
			ft_main2(fd);
		}
		else
			ft_putstr("error\n");
		close(fd);
	}
	return (0);
}

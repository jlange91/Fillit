/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:08:56 by jlange            #+#    #+#             */
/*   Updated: 2016/11/23 20:54:17 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_main2(char **av, int fd)
{
	char		*file;
	t_map		map;
	t_tetri		*tetri;

	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if (!(file = ft_getfile(fd, &map)) ||
				!(ft_check_file(file)))
			ft_putstr("map error");
		else
		{
			tetri = ft_create_tetri(map);
			ft_fill(tetri, file, map);
			ft_init_map(&map);
			ft_solve(tetri, &map);
			while (map.ret == 0)
			{
				map.size++;
				ft_solve(tetri, &map);
			}
			ft_print_list(tetri);
			ft_print_map(map);
		}
		close(fd);
	}
	else
		ft_putstr("error");
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putstr("usage :");
	else
		ft_main2(av, 0);
	return (0);
}

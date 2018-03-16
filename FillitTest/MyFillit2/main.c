/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:08:56 by jlange            #+#    #+#             */
/*   Updated: 2016/11/30 22:23:05 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(t_list *tetri, t_map map);

void	ft_main2(char **av, int fd)
{
	char		*file;
	t_list		*tetri;
	t_map		map;
	t_mask		mask;

	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if (!(file = ft_getfile(fd)) ||
				!(ft_check_file(file)))
			ft_putstr("map error");
		else
		{
			ft_init_map(&map);
			ft_init_mask(&mask);
//			tetri = ft_fill(file, &map.nb_tetri);
//			ft_find_min_max(&map);
//			ft_init_tetri_size(tetri);
//			ft_test_list(tetri);
		/*	ft_solve(tetri, &map, mask);
			while (map.ret == 0)
			{
				map.size++;
				ft_solve(tetri, &map, mask);
			}
			ft_test_list(tetri);
			ft_putstr("map 0 :\n");
			ft_print_bits(map.map[0]);
			printf("\n\n");
			ft_putstr("map 2 :\n");
			ft_print_bits(map.map[2]);
			printf("\n\n");
			ft_putstr("map 6 :\n");
			ft_print_bits(map.map[6]);
			printf("\n\n");
			ft_putstr("map 8 :\n");
			ft_print_bits(map.map[8]);
			ft_print_map(tetri,map);
			printf("\n%d\n", map.size);*/
		}
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

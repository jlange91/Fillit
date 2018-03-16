/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:08:56 by jlange            #+#    #+#             */
/*   Updated: 2016/11/22 15:54:40 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(t_list *tetri, t_map map);
void	ft_create_map(t_map *map, t_mask mask);

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
			tetri = ft_fill(file, &map.nb_tetri);
			ft_find_min_max(&map);
			ft_init_tetri_size(tetri);
			ft_display_map_info(map);
			ft_solve(tetri, &map, mask);
			while (map.ret == 0)
			{
				reset_tetri(tetri);
				ft_solve(tetri, &map, mask);
				map.size++;
			}
			ft_test_list(tetri);
	/*		ft_putstr("map 0 :\n");
			ft_print_bits(map.map[0]);
			printf("\n\n");
			ft_putstr("map 2 :\n");
			ft_print_bits(map.map[2]);
			printf("\n\n");
			ft_putstr("map 6 :\n");
			ft_print_bits(map.map[6]);
			printf("\n\n");
			ft_putstr("map 8 :\n");
			ft_print_bits(map.map[8]);*/
			ft_print_map(tetri,map);
			printf("\n%d\n", map.size);

		/*	map.map[0] = 453253435;
			map.map[2] = 1531254245;
			map.map[6] = 4356753424354;
			map.map[8] = 41424752425;
			ft_create_map(&map, mask);
			ft_print_bits(map.map[0]);
			ft_putchar('\n');
			ft_putchar('\n');
			ft_print_bits(map.map[3]);
			ft_putchar('\n');
			ft_putchar('\n');
			ft_print_bits(map.map[6]);
			ft_putchar('\n');
			ft_putchar('\n');*/
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

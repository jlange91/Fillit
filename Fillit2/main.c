/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:08:56 by jlange            #+#    #+#             */
/*   Updated: 2016/12/01 00:15:00 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	creat_trti2(t_tetri *lst, t_tetri *tab)
{
	int	i;

	i = 0;
	while (lst)
	{
		tab[i] = *lst;
		lst = lst->next;
		if (i > 0)
			tab[i - 1].next = tab + i;
		i++;
	}
}

void	ft_init_size_tetri(t_tetri *tetri);

void	ft_main2(char **av, int fd)
{
	char		*file;
	t_map		map;
	t_tetri		*tetri;
	t_tetri		tetri2[26];

	if ((fd = open(av[1], O_RDONLY)) != -1)
	{
		if (!(file = ft_getfile(fd, &map)) ||
				!(ft_check_file(file)))
			ft_putstr("map error");
		else
		{
			tetri = ft_create_tetri(map);
			ft_fill(tetri, file, map);
			ft_init_size_tetri(tetri);
			ft_init_map(&map);
			map.ret = 1;
			ft_solve(tetri, &map);
			while (map.ret == 0)
			{
				map.size++;
				ft_solve(tetri, &map);
			}
			ft_print_map(tetri, map);
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

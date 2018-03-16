/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:55:16 by jlange            #+#    #+#             */
/*   Updated: 2016/11/30 23:41:10 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_max_left(t_tetri *tetri)
{
	while ((tetri->tetriminos & ~ft_vertical_mask(1)) == 0)
		tetri->tetriminos >>= 1;
}

void	ft_max_right(t_tetri *tetri)
{
	while ((tetri->tetriminos & ft_vertical_mask(15)) == 0)
		tetri->tetriminos <<= 1;
}

void	ft_max_up(t_tetri *tetri)
{
	while ((tetri->tetriminos & ~ft_horizontal_mask(1)) == 0)
		tetri->tetriminos >>= 16;
}

void	ft_max_down(t_tetri *tetri)
{
	while ((tetri->tetriminos & ft_horizontal_mask(3)) == 0)
		tetri->tetriminos <<= 16;
}

void	ft_top_left(t_tetri *tetri)
{
	ft_max_left(tetri);
	ft_max_up(tetri);
}

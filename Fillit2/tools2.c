/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:27:05 by jlange            #+#    #+#             */
/*   Updated: 2016/11/24 10:28:03 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_reset_tetri2(t_tetri *tetri)
{
	tetri->x = 0;
	tetri->y = 0;
	ft_top_left(tetri);
}

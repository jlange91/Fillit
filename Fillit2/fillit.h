/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:47:07 by jlange            #+#    #+#             */
/*   Updated: 2016/11/24 13:03:08 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Libft/includes/libft.h"

typedef struct	s_map
{
	short			map[16];
	int				max_size;
	int				min_size;
	int				size;
	int				nb_tetri;
	int				ret;
}				t_map;

typedef struct	s_tmp
{
	int				id;
	unsigned long	tetriminos;
	int				x;
	int				y;
	short			width;
	short			length;
}				t_tmp;

typedef struct	s_tetri
{
	int				id;
	unsigned long	tetriminos;
	int				x;
	int				y;
	short			width;
	short			length;
	struct s_tetri	*next;
}				t_tetri;

typedef struct	s_mask
{
}
				t_mask;

// fonction de verification des pieces envoyees
char			*ft_getfile(int fd, t_map *map);
int				ft_check_file(char *file);

// fonction d'initialisation
t_tetri			*ft_create_tetri(t_map map);
t_tetri			*ft_init_tetri(int i);
void			ft_fill(t_tetri *tetri, char *file, t_map map);
void			ft_init_map(t_map *map);

// fonction pour remplir la grille
void			ft_solve(t_tetri *tetri, t_map *map);

void			ft_reset_tetri(t_tetri *tetri);
void			ft_reset_tetri2(t_tetri *tetri);
t_tmp			save_tetri(t_tetri *tetri);
void			tmp_tetri(t_tetri *tetri, t_tmp tmp);

void			ft_max_left(t_tetri *tetri);
void			ft_max_right(t_tetri *tetri);
void			ft_max_up(t_tetri *tetri);
void			ft_max_down(t_tetri *tetri);
void			ft_top_left(t_tetri *tetri);

unsigned long	ft_vertical_mask(int x);
unsigned long	ft_horizontal_mask(int x);

void			ft_print_map(t_tetri *tetri, t_map map);

// fonction de test
void	print_map(t_map map);
void	ft_print_list(t_tetri *tetri);
void	ft_print_bits(unsigned long nb);
void	ft_print_tetri(t_tetri *tetri);
void	ft_print_bits_map(short nb);

#endif

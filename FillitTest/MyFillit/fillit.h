/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:47:07 by jlange            #+#    #+#             */
/*   Updated: 2016/11/17 21:14:35 by jlange           ###   ########.fr       */
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

#define TETRI ((t_tetri *)tetri->content)->tetriminos
#define TETRI_X ((t_tetri *)tetri->content)->x
#define TETRI_Y ((t_tetri *)tetri->content)->y
#define TETRI_WIDTH ((t_tetri *)tetri->content)->width
#define TETRI_LENGTH ((t_tetri *)tetri->content)->length
#define TETRI_MAP ((t_tetri *)tetri->content)->map

#define MAP(y) map->map[y]

typedef struct	s_map
{
	unsigned long	map[9];
	int				max_size;
	int				min_size;
	int				size;
	int				nb_tetri;
	int				ret;
}				t_map;

typedef struct	s_tetri
{
	int				id;
	unsigned long	tetriminos;
	int				x;
	int				y;
	short			width;
	short			length;
	short			map;
}				t_tetri;

typedef struct	s_mask
{
	unsigned long	vertical_l;
	unsigned long	vertical_r;
	unsigned long	horizontal_u;
	unsigned long	horizontal_d;
	unsigned long	top_left;
	unsigned long	top_right;
	unsigned long	bottom_left;
	unsigned long	bottom_right;
	unsigned long	up;
	unsigned long	down;
	unsigned long	left;
	unsigned long	right;
}				t_mask;

unsigned long	ft_top_left(unsigned long i);
unsigned long	ft_max_left(unsigned long i);
unsigned long	ft_max_right(unsigned long i);
unsigned long	ft_max_up(unsigned long i);
unsigned long	ft_max_down(unsigned long i);

unsigned long	ft_horizontal_mask(int x);
unsigned long	ft_vertical_mask(int x);

// fonction pour remplir les unsigned long
t_list			*ft_fill(char *file, int *nb);
unsigned long	ft_fill_tetri(char *file);
t_tetri			*ft_tetrinew(void);

// initialisation des variables dans les structures
void			ft_init_tetri_size(t_list *tetri);
void			ft_init_map(t_map *map);
void			ft_init_mask(t_mask *mask);
void			ft_find_min_max(t_map *map);

// fonction de verification des pieces envoyees
char			*ft_getfile(int fd);
char			*ft_strcharjoin(char *s1, char s2);
int				ft_check_file(char *file);
int				ft_check_tetriminos1(char *file);
int				ft_check_tetriminos2(char *file);

// fonction outils pour remplir la grille
t_tetri			save_tetri(t_list *tetri);
void			tmp_tetri(t_list *tetri, t_tetri tmp);
void			reset_tetri(t_list *tetri);

// fonction pour remplir la grille
int				ft_put_tetri(t_list *tetri, t_map *map, t_mask mask);
void			ft_solve(t_list *tetri, t_map *map, t_mask mask);

// fonction de test
void	ft_print_bits(unsigned long nb);
void	ft_test_list(t_list *list);
void	ft_display_map_info(t_map map);
void	ft_display_mask(t_mask mask);

#endif

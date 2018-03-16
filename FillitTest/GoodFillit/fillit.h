/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:31:59 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/20 19:22:09 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define POS(x) (*map)[p + (*f).pos[x][0] * (n + 1) + (*f).pos[x][1]]
# define FREE(x) (*map)[*p + f->pos[x][0] *(l->min + 1) + f->pos[x][1]] == '.'

typedef struct	s_fillit
{
	int		p;
	int		pos[4][2];
	char	c;
}				t_fillit;

typedef struct	s_info
{
	int		min;
	int		n;
}				t_info;

typedef struct	s_rec
{
	int		j;
	int		i;
	char	c;
	int		count;
}				t_rec;

typedef struct	s_rec2
{
	int		nb;
	int		p;
	int		max;
	int		i;
}				t_rec2;

void			fill_some(t_fillit **linear, int n);
t_fillit		*full_it(char *file, t_info *l);
int				resolve(t_fillit **f, t_info *l, char **map);
char			*filetobuff(char *file);
int				check(char *file);

#endif

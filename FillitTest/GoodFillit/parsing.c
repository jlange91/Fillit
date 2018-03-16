/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:58:08 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/20 19:25:52 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*filetobuff(char *file)
{
	char	*buffer;
	int		fd;

	buffer = (char *)malloc(sizeof(char) * 570);
	fd = open(file, O_RDONLY);
	read(fd, buffer, 570);
	close(fd);
	return (buffer);
}

char		*remove_newlines(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		if (str[i] != '\n' || (str[i] == '\n' && str[i - 1] == '\n'))
		{
			new[j] = str[i];
			j++;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}

t_fillit	*get_pos(char **tab)
{
	t_fillit	*new;
	t_rec		g;

	g.i = 0;
	g.j = 0;
	g.c = 'A';
	g.count = 0;
	new = (t_fillit *)malloc(sizeof(t_fillit) * 26);
	while (tab[g.i])
	{
		while (tab[g.i][g.j])
		{
			if (tab[g.i][g.j] == '#')
			{
				(new[g.i].pos)[g.count][0] = g.j / 4;
				(new[g.i].pos)[g.count][1] = g.j % 4;
				g.count++;
			}
			g.j++;
		}
		new[g.i++].c = g.c++;
		g.count = 0;
		g.j = 0;
	}
	return (new);
}

void		correct_pos(t_fillit *pos, int nb)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < nb)
	{
		if ((pos[i].pos)[0][1] != 0)
		{
			n = (pos[i].pos)[0][1];
			(pos[i].pos)[0][1] = 0;
			(pos[i].pos)[1][1] -= n;
			(pos[i].pos)[2][1] -= n;
			(pos[i].pos)[3][1] -= n;
		}
		if ((pos[i].pos)[1][0] != 0)
		{
			n = (pos[i].pos)[0][0];
			(pos[i].pos)[0][0] = 0;
			(pos[i].pos)[1][0] -= n;
			(pos[i].pos)[2][0] -= n;
			(pos[i].pos)[3][0] -= n;
		}
		i++;
	}
}

t_fillit	*full_it(char *file, t_info *l)
{
	char		*buf;
	char		*forbuf;
	char		**te2;
	t_fillit	*linear;

	buf = filetobuff(file);
	forbuf = remove_newlines(buf);
	te2 = ft_strsplit(forbuf, '\n');
	free(buf);
	l->n = 0;
	while (te2[l->n])
		l->n++;
	linear = (t_fillit *)malloc(sizeof(t_fillit) * l->n);
	linear = get_pos(te2);
	correct_pos(linear, l->n);
	fill_some(&linear, l->n);
	return (linear);
}

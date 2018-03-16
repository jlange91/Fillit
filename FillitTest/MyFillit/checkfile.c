/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:29:53 by jlange            #+#    #+#             */
/*   Updated: 2016/11/20 23:39:39 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_tetriminos2(char *file)
{
	int i;
	int touch;

	i = -1;
	while (file[++i])
	{
		touch = 0;
		while ((file[i] != '\n' || file[i + 1] != '\n') && file[i])
		{
			touch = (file[i] == '#' && file[i + 1] == '#') ? touch + 1 : touch;
			touch = (file[i] == '#' && file[i - 1] == '#') ? touch + 1 : touch;
			touch = (file[i] == '#' && file[i + 5] == '#') ? touch + 1 : touch;
			touch = (file[i] == '#' && file[i - 5] == '#') ? touch + 1 : touch;
			i++;
		}
		if (touch < 6)
			return (0);
	}
	return (1);
}

int		ft_check_tetriminos1(char *file)
{
	int i;
	int full;
	int empty;
	int line;

	i = -1;
	while (file[++i])
	{
		full = 0;
		empty = 0;
		line = 0;
		while ((file[i] != '\n' || file[i + 1] != '\n') && file[i])
		{
			full = (file[i] == '#') ? full + 1 : full;
			empty = (file[i] == '.') ? empty + 1 : empty;
			line = (file[i] == '\n' && file[i - 1] != '\n' && file[i + 1])
				? line + 1 : line;
			i++;
		}
		if (full != 4 || empty != 12 || line != 3)
			return (0);
	}
	return (1);
}

int		ft_check_file(char *file)
{
	return (ft_check_tetriminos1(file) && ft_check_tetriminos2(file)) ? 1 : 0;
}

char	*ft_strcharjoin(char *s1, char s2)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	i = -1;
	if (ptr == NULL || !s1 || !s2)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	if (s1[i] == '\0')
		ptr[i] = s2;
	ptr[++i] = '\0';
	return (ptr);
}

char	*ft_getfile(int fd)
{
	static	char	data[546];
	int				ret;

	if ((ret = read(fd, data, 546)) < 0 || ret == 546 || ((ret - 20) % 21) != 0)
		return (NULL);
	else
		return (data);
}

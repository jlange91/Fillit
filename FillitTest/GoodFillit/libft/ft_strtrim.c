/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 18:25:05 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/07 15:23:09 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getbegin(char const *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		&& str[i])
		i++;
	return (i);
}

static int	getend(char const *str)
{
	int	i;

	i = ft_strlen(str);
	i--;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		&& str[i])
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		begin;
	int		end;
	char	*new;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if ((new = (char *)malloc(sizeof(char))) == NULL)
		return (NULL);
	new[0] = 0;
	begin = getbegin(s);
	end = getend(s);
	if (end <= begin)
		return (new);
	if ((new = ft_strsub(s, begin, (end - begin + 1))) == NULL)
		return (NULL);
	new[ft_strlen(s)] = 0;
	return (new);
}

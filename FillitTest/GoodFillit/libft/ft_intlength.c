/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:30:43 by ataguiro          #+#    #+#             */
/*   Updated: 2016/11/07 12:07:57 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlength(long long int n)
{
	int				len;
	int				neg;
	long long int	nb;

	nb = n;
	neg = 0;
	len = 0;
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	while ((nb /= 10))
		len++;
	if (neg)
		len++;
	len++;
	return (len);
}

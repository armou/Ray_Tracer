/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:35:46 by daugier           #+#    #+#             */
/*   Updated: 2017/08/06 18:29:42 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FT_JOIN ft_strjoin

char		*ft_ftoa(double nbr)
{
	float	floating;
	char	*tmp;
	int		neg;
	int		precision;

	precision = -1;
	if (!(tmp = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	tmp[0] = '\0';
	neg = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	floating = nbr - (int)nbr;
	while (floating > 0.0001 && ++precision < 5)
	{
		if ((floating = floating * 10) && ((int)(floating + 0.1) + '0') == ':')
			break ;
		tmp = ft_charjoin(tmp, ((int)(floating + 0.1) + '0'));
		floating -= (int)floating;
	}
	while (++precision < 6)
		tmp = ft_charjoin(tmp, '0');
	if (neg)
		return (FT_JOIN(FT_JOIN("-", FT_JOIN(ft_itoa((int)nbr), ".")), tmp));
	return (FT_JOIN(FT_JOIN(ft_itoa((int)nbr), "."), tmp));
}

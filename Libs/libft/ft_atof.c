/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:11:17 by daugier           #+#    #+#             */
/*   Updated: 2017/08/06 17:58:14 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_atof(char const *str)
{
	int		i;
	int		neg;
	double	result;
	int		k;

	i = 0;
	result = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	neg = (str[i] == '-') ? -1 : 1;
	i = (str[i] == '-' || str[i] == '+') ? ++i : i;
	while (str[i] <= '9' && str[i] >= '0' && str[i] && ((i - k < 6) || k == 0))
	{
		result = result * 10 + str[i++] - '0';
		if (str[i] == '.' && k == 0)
			k = i++;
	}
	if (k)
		while (++k < i)
			neg *= 10;
	return (result / neg);
}

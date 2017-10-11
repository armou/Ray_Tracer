/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ten.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 00:49:01 by daugier           #+#    #+#             */
/*   Updated: 2016/06/21 00:51:31 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_convert_ten(char *nbr, char *base_from)
{
	int i;
	int j;
	int k;
	int result;
	int n;

	i = ft_strlen(nbr) - 1;
	j = ft_strlen(base_from);
	result = 0;
	n = 0;
	while (i > -1)
	{
		k = 0;
		while (base_from[k] != nbr[n])
			k++;
		result = result + k * ft_recursive_power(j, i);
		i--;
		n++;
	}
	return (result);
}

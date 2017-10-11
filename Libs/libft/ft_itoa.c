/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 12:46:57 by ddufour           #+#    #+#             */
/*   Updated: 2017/02/08 17:08:07 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char		*nbr;
	int			a;
	long int	tmp;

	tmp = n;
	a = 1;
	while (n /= 10)
		a++;
	a += (tmp < 0) ? 1 : 0;
	if ((nbr = ft_strnew(a)) == NULL)
		return (NULL);
	if (tmp < 0)
	{
		nbr[0] = '-';
		tmp *= -1;
	}
	if (tmp == 0)
		nbr[0] = '0';
	while (tmp)
	{
		nbr[--a] = '0' + tmp % 10;
		tmp = tmp / 10;
	}
	return (nbr);
}

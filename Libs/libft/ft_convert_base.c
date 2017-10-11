/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 21:07:23 by daugier           #+#    #+#             */
/*   Updated: 2016/06/21 01:11:46 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		j;
	int		n;
	int		m;
	char	*str;

	i = ft_convert_ten(nbr, base_from);
	j = ft_strlen(base_to);
	n = 1;
	m = 0;
	while ((i = i / j) > 0)
		n++;
	str = (char*)malloc(sizeof(char) * (n + 1));
	if (ft_convert_ten(nbr, base_from) == 0)
	{
		str[m++] = '0';
		str[m] = '\0';
		return (str);
	}
	n = ft_convert_ten(nbr, base_from) * j;
	while ((n = n / j) > 0)
		str[m++] = base_to[n % j];
	str[m] = '\0';
	str = ft_strrev(str);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 21:28:56 by ddufour           #+#    #+#             */
/*   Updated: 2016/05/26 21:59:40 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t len_s1;
	size_t a;

	a = -1;
	len_s1 = ft_strlen(s1);
	while (s2[++a])
		s1[len_s1 + a] = s2[a];
	s1[len_s1 + a] = '\0';
	return (s1);
}

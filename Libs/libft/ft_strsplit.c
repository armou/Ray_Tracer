/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 18:42:54 by ddufour           #+#    #+#             */
/*   Updated: 2017/04/14 11:40:31 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		char_count(char const *s, char c, int a)
{
	int b;

	b = 0;
	while (s[a] != c && s[a])
	{
		b++;
		a++;
	}
	return (b);
}

static int		size_tab(char const *s, char c)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (s[a])
	{
		if (s[a] != c && s[a] != '\0')
		{
			while (s[a] != c && s[a] != '\0')
				a++;
			if (s[a - 1] != c && s[a] != '\0')
				b++;
		}
		else
			a++;
	}
	return (b);
}

static	char	**cpytab(char const *s, char c, int a, char **tab)
{
	int d;
	int b;

	b = -1;
	while (s[a] != '\0')
	{
		if (s[a] != c)
		{
			d = 0;
			if ((tab[++b] = (char*)ft_memalloc(sizeof(char)
				* (char_count(s, c, a) + 1))) == NULL)
				return (NULL);
			while (s[a] != c && s[a] != '\0')
				tab[b][d++] = s[a++];
		}
		else
			a++;
	}
	tab[b + 1] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	int		a;
	char	**tab;

	if (!(a = size_tab(s, c)))
		return (NULL);
	if (!s || !(tab = (char**)ft_memalloc(sizeof(char*) * (a + 2))))
		return (NULL);
	if (!(tab = cpytab(s, c, 0, tab)))
		return (NULL);
	return (tab);
}

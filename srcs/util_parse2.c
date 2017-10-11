/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 19:51:26 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 21:12:58 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		*balise_flag(char *s)
{
	ft_printf("\033[31mbalise %s is missing : \n", s);
	exit(EXIT_SUCCESS);
}

int			incr_i(char **cpy, int *i, char *first, int *bis)
{
	*i = 0;
	while ((*cpy)[*i] && ft_strncmp(*cpy + *i, first, ft_strlen(first)) != 0)
		(*i)++;
	if (!(*cpy)[*i])
		if (balise_flag(first) == NULL)
			return (0);
	*cpy = delete_str_in_str(*cpy, first, ft_strlen(first));
	*bis = *i - 1;
	(*i)--;
	return (1);
}

char		*stock_balise(char **scene, char *first, char *second)
{
	int		i;
	char	*tmp;
	int		bis;
	char	*cpy;

	tmp = NULL;
	cpy = *scene;
	if (incr_i(&cpy, &i, first, &bis) == 0)
		return (NULL);
	while (cpy[++i] && ft_strncmp(cpy + i, second, ft_strlen(second)) != 0)
		if (ft_strncmp(cpy + i, first, ft_strlen(first)) == 0)
			return (balise_flag(second));
	if (!cpy[i])
		return (balise_flag(first));
	tmp = (char *)malloc(sizeof(char) * i - bis + 1);
	i = 0;
	while (cpy[++bis] && ft_strncmp(cpy + bis, second, ft_strlen(second)) != 0)
	{
		tmp[i++] = cpy[bis];
		cpy[bis] = ' ';
	}
	tmp[i] = '\0';
	cpy = delete_str_in_str(cpy, second, ft_strlen(second));
	*scene = cpy;
	return (tmp);
}

void		cpy_texture2(SDL_Surface *tex, int *a, int *b, int *c)
{
	*a = tex->pitch;
	*b = tex->w;
	*c = tex->h;
}

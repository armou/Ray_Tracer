/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:05:14 by daugier           #+#    #+#             */
/*   Updated: 2017/10/05 22:02:10 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int			get_color(char **str, t_color *o_color)
{
	int		i;
	char	*tmp;

	i = -1;
	if (*str == NULL)
		return (-1);
	*str = delete_space(*str);
	if (ft_strlen(*str) > 6)
	{
		ft_printf("\033[31mSize of color too much long :\n%s\n", *str);
		return (-1);
	}
	if (*str != NULL)
	{
		tmp = ft_convert_base(*str, HEXA, DECI);
		i = ft_atoi(tmp);
		free(tmp);
	}
	get_rgb_from_int(i, o_color);
	return (i);
}

void		next_car(char *file, int *i, char c)
{
	while (file[*i] != c && file[*i])
		(*i)++;
	if (file[*i] == c && file[*i])
		(*i)++;
	else
		(*i) = 0;
}

int			stock_origin(char **file, t_pos *origin)
{
	char	*orig;
	int		i;

	i = 0;
	if ((orig = stock_balise(file, "<origin>", "</origin>")) == NULL)
		return (0);
	origin->x = ft_atof(orig);
	next_car(orig, &i, ',');
	origin->y = ft_atof(orig + i);
	next_car(orig, &i, ',');
	origin->z = ft_atof(orig + i);
	if (i == 0)
		return (0);
	next_car(orig, &i, ' ');
	free(orig);
	return (1);
}

int			stock_rotation(char **file, t_pos *rot)
{
	char	*rotation;
	int		i;

	i = 0;
	if ((rotation = stock_balise(file, "<rotation>", "</rotation>")) == NULL)
		return (0);
	rot->x = ft_atof(rotation);
	next_car(rotation, &i, ',');
	rot->y = ft_atof(rotation + i);
	next_car(rotation, &i, ',');
	rot->z = ft_atof(rotation + i);
	if (i == 0)
		return (0);
	next_car(rotation, &i, ' ');
	free(rotation);
	return (1);
}

int			stock_trois(char **file, t_pos *rot)
{
	char	*rotation;
	int		i;

	i = 0;
	if ((rotation = stock_balise(file, "<trois>", "</trois>")) == NULL)
		return (0);
	rot->x = ft_atof(rotation);
	next_car(rotation, &i, ',');
	rot->y = ft_atof(rotation + i);
	next_car(rotation, &i, ',');
	rot->z = ft_atof(rotation + i);
	if (i == 0)
		return (0);
	next_car(rotation, &i, ' ');
	free(rotation);
	return (1);
}

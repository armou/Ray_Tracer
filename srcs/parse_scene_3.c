/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:55:49 by daugier           #+#    #+#             */
/*   Updated: 2017/10/05 21:58:27 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

float		stock_size(char **file)
{
	char	*size_tmp;
	float	size;

	if ((size_tmp = stock_balise(file, "<size>", "</size>")) == NULL)
		return (0);
	if ((size = ft_atof(size_tmp)) <= 0)
		return (f_error("size must be > to 0 : ", size_tmp));
	free(size_tmp);
	return (size);
}

float		stock_size_plan(char **file)
{
	char	*size_tmp;
	float	size;

	if ((size_tmp = stock_balise(file, "<size>", "</size>")) == NULL)
		return (-1);
	if ((size = ft_atof(size_tmp)) < 0)
		return (-1);
	free(size_tmp);
	return (size);
}

float		stock_b_size(char **file)
{
	char	*size_tmp;
	float	size;

	if ((size_tmp = stock_balise(file, "<size2>", "</size2>")) == NULL)
		return (0);
	if ((size = ft_atof(size_tmp)) <= 0)
		return (f_error("size must be > to 0 : ", size_tmp));
	free(size_tmp);
	return (size);
}

float		stock_reflection(char **file)
{
	char	*size_tmp;
	float	size;

	if (!(size_tmp = stock_balise(file, "<reflection>", "</reflection>")))
		return (0);
	if ((size = ft_atof(size_tmp)) < 0 || size > 1)
	{
		ft_printf("reflection must be between 0 and 1 : %s\n", size_tmp);
		return (-1);
	}
	free(size_tmp);
	return (size);
}

int			stock_texture(char **file)
{
	char	*tex_tmp;
	int		tex;

	if (!(tex_tmp = stock_balise(file, "<texture>", "</texture>")))
		return (-1);
	if ((tex = ft_atoi(tex_tmp)) < 0)
		return (f_error("Texture must be >= 0 : ", tex_tmp));
	free(tex_tmp);
	return (tex);
}

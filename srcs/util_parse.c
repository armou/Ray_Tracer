/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:46:36 by daugier           #+#    #+#             */
/*   Updated: 2017/10/05 21:57:23 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		get_rgb_from_int(int col, t_color *color)
{
	color->r = (float)(((col >> 16) & 255) / 255.0f);
	color->g = (float)(((col >> 8) & 255) / 255.0f);
	color->b = (float)(((col) & 255) / 255.0f);
}

int			f_error(char *error_msg, char *file_error)
{
	ft_putstr(error_msg);
	ft_putstr(file_error);
	ft_putstr("\n");
	exit(EXIT_SUCCESS);
	return (0);
}

char		*delete_space(char *file)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(file) + 1);
	while (file[i])
	{
		if (file[i] != 32 && file[i] != '\n' && file[i] != '\t')
			tmp[j++] = file[i++];
		else
			i++;
	}
	free(file);
	tmp[j] = '\0';
	return (tmp);
}

char		*delete_str_in_str(char *big, char *little, int size)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (big[i])
	{
		if (ft_memcmp(big + i, little, ft_strlen(little)) == 0)
		{
			while (len < (size_t)size)
			{
				big[i] = ' ';
				i++;
				len++;
			}
			break ;
		}
		i++;
	}
	return (big);
}

int			check_balise(char *scene, char *first)
{
	int		i;

	i = 0;
	while (scene[i] && ft_strncmp(scene + i, first, ft_strlen(first)) != 0)
		i++;
	if (!scene[i])
		return (0);
	return (1);
}

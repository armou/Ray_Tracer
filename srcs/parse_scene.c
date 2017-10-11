/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:06:28 by daugier           #+#    #+#             */
/*   Updated: 2017/10/05 20:56:42 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int			parse_camera(t_rt *rtv1, char *camera)
{
	char		*err;

	if (stock_origin(&camera, &rtv1->camera.origin) == 0)
		return (f_error("too much or few arguments for origin camera", ""));
	if (stock_rotation(&camera, &rtv1->camera.rot) == 0)
		return (f_error("too much or few arguments for rotation camera", ""));
	if ((err = delete_space(camera)) && err[0] != '\0')
		return (f_error("too much arguments for camera : ", camera));
	free(err);
	return (1);
}

int			stock_object(char *file, t_rt *rtv1)
{
	char		*scene;

	if (!(scene = ft_read_file(file)))
	{
		ft_printf("%s : file doesn't exist\n", file);
		return (0);
	}
	if (!parse_scene(rtv1, scene))
		return (0);
	return (1);
}

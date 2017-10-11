/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:34:19 by David             #+#    #+#             */
/*   Updated: 2017/10/05 22:33:35 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		rotate_x(t_rt *rtv1)
{
	double	y_tmp;
	double	z_tmp;
	double	angle;

	angle = DEG_TO_RAD(rtv1->camera.rot.x);
	y_tmp = rtv1->camera.dir.y;
	z_tmp = rtv1->camera.dir.z;
	rtv1->camera.dir.y = y_tmp * cos(angle) - z_tmp * sin(angle);
	rtv1->camera.dir.z = y_tmp * sin(angle) + z_tmp * cos(angle);
}

void		rotate_y(t_rt *rtv1)
{
	double	x_tmp;
	double	z_tmp;
	double	angle;

	angle = DEG_TO_RAD(rtv1->camera.rot.y);
	x_tmp = rtv1->camera.dir.x;
	z_tmp = rtv1->camera.dir.z;
	rtv1->camera.dir.z = z_tmp * cos(angle) - x_tmp * sin(angle);
	rtv1->camera.dir.x = z_tmp * sin(angle) + x_tmp * cos(angle);
}

void		rotate_z(t_rt *rtv1)
{
	double	x_tmp;
	double	y_tmp;
	double	angle;

	angle = DEG_TO_RAD(rtv1->camera.rot.z);
	x_tmp = rtv1->camera.dir.x;
	y_tmp = rtv1->camera.dir.y;
	rtv1->camera.dir.x = x_tmp * cos(angle) - y_tmp * sin(angle);
	rtv1->camera.dir.y = x_tmp * sin(angle) + y_tmp * cos(angle);
}

t_object	*list_into_tab(t_object *obj, int *nb)
{
	t_object	*tmp;
	t_object	*tab;
	int			i;

	*nb = 0;
	tmp = obj;
	while (tmp)
	{
		tmp = tmp->next;
		(*nb) += 1;
	}
	if (*nb == 0 || (tab = malloc(sizeof(t_object) * (*nb))) == NULL)
		return (NULL);
	tmp = obj;
	i = 0;
	while (tmp)
	{
		tab[i] = *tmp;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}

int			draw_rt(t_rt *rtv1)
{
	int			error;
	size_t		giz[2];

	giz[0] = (WIDTH / 10);
	giz[1] = (HEIGHT / 10);
	if ((rtv1->tab_object = list_into_tab(rtv1->object,
		&rtv1->nb_object)) == NULL)
		return (-1);
	rtv1->opencl.moove = rtv1->moove;
	rtv1->opencl.al = rtv1->aliasing;
	rtv1->opencl.density = rtv1->density;
	rtv1->opencl.filter = rtv1->filter;
	rtv1->opencl.motion_b = rtv1->motion_blur;
	rtv1->opencl.ambiante = rtv1->ambiante;
	if ((error = cl_read_buffer(rtv1, &rtv1->kernel, &rtv1->cl_b,
			giz)) != CL_SUCCESS)
	{
		ft_printf("%d\n", error);
		return (-1);
	}
	SDL_UpdateWindowSurface(rtv1->window);
	free(rtv1->tab_object);
	return (0);
}

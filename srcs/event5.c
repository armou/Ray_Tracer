/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:06:08 by David             #+#    #+#             */
/*   Updated: 2017/10/05 20:56:24 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	set_ray_add(t_rt *rtv1)
{
	rtv1->camera.dir.x = (2 * ((0.5) / (float)WIDTH) - 1) * ANGLE * ASPECTRATIO;
	rtv1->camera.dir.y = (1 - 2 * ((0.5) / HEIGHT)) * ANGLE;
	rtv1->camera.dir.z = 0;
	rotate_x(rtv1);
	rotate_y(rtv1);
	rotate_z(rtv1);
	vector_norm(&rtv1->camera.dir);
}

void	set_object_info(t_object *tmp, t_rt *rtv1)
{
	tmp->number = rtv1->nb_object;
	tmp->texture = 3;
	tmp->reflection = 0.5;
	tmp->color = (t_color){0.5, 0.7, 0.9, 0};
	tmp->texture = 4;
	tmp->next = NULL;
}

void	add_torus(t_rt *rtv1)
{
	t_object	*tmp;
	t_object	*cpy;
	int			i;

	i = 0;
	tmp = rtv1->object;
	while (tmp && ++i)
	{
		cpy = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_object *)malloc(sizeof(t_object))))
		return ;
	tmp->type = 6;
	set_ray_add(rtv1);
	set_object_info(tmp, rtv1);
	tmp->origin = vector_sub(&rtv1->camera.origin, &rtv1->camera.dir);
	tmp->rot = vector_sub(&rtv1->camera.rot, &rtv1->camera.dir);
	tmp->size = 0.5;
	tmp->b_size = 0.9;
	if (i == 0)
		rtv1->object = tmp;
	else
		cpy->next = tmp;
	rtv1->nb_object++;
}

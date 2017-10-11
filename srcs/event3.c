/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:06:08 by David             #+#    #+#             */
/*   Updated: 2017/10/05 21:15:49 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	add_triangle(t_rt *rtv1)
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
	tmp->type = 7;
	set_object_info(tmp, rtv1);
	tmp->origin = vector_scale(&rtv1->camera.origin, 1);
	tmp->rot = vector_scale(&rtv1->camera.origin, 0.9f);
	tmp->trois = vector_scale(&rtv1->camera.origin, -0.9f);
	tmp->origin.z -= 2;
	if (i == 0)
		rtv1->object = tmp;
	else
		cpy->next = tmp;
}

void	add_plan(t_rt *rtv1)
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
	set_ray_add(rtv1);
	set_object_info(tmp, rtv1);
	tmp->origin = vector_sub(&rtv1->camera.origin, &rtv1->camera.dir);
	tmp->rot = vector_sub(&rtv1->camera.rot, &rtv1->camera.dir);
	tmp->type = 4;
	tmp->origin.z -= 3;
	tmp->size = 0.4;
	tmp->b_size = 0.5;
	if (i == 0)
		rtv1->object = tmp;
	else
		cpy->next = tmp;
}

void	add_sphere(t_rt *rtv1)
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
	set_ray_add(rtv1);
	set_object_info(tmp, rtv1);
	tmp->type = 1;
	tmp->origin = vector_sub(&rtv1->camera.origin, &rtv1->camera.dir);
	tmp->size = 1;
	tmp->b_size = 1;
	if (i == 0)
		rtv1->object = tmp;
	else
		cpy->next = tmp;
}

void	add_light(t_rt *rtv1)
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
	set_ray_add(rtv1);
	set_object_info(tmp, rtv1);
	tmp->type = 5;
	tmp->origin = vector_sub(&rtv1->camera.origin, &rtv1->camera.dir);
	tmp->size = 0.5;
	tmp->b_size = 1;
	if (i == 0)
		rtv1->object = tmp;
	else
		cpy->next = tmp;
}

void	add_alter(t_rt *rtv1)
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
	vector_norm(&rtv1->camera.dir);
	set_ray_add(rtv1);
	tmp->type = 9;
	tmp->origin = vector_sub(&rtv1->camera.origin, &rtv1->camera.dir);
	tmp->rot = vector_sub(&rtv1->camera.rot, &rtv1->camera.dir);
	set_object_info(tmp, rtv1);
	tmp->size = 0.2;
	tmp->b_size = 1;
	if (i == 0)
		rtv1->object = tmp;
	else
		cpy->next = tmp;
}

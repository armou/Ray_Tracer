/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitobject.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:39:15 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 20:56:14 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	cone_tape(t_camera *camera, t_object *obj, float *tnear,
		t_object **hitobject)
{
	float		tneark;

	tneark = MAXFLOAT;
	if (cone_hit(camera, obj, &tneark) && tneark < *tnear && tneark > 0.0001f)
	{
		*tnear = tneark;
		*hitobject = obj;
	}
}

void	sphere_tape(t_camera *camera, t_object *obj, float *tnear,
		t_object **hitobject)
{
	float		tneark;

	tneark = MAXFLOAT;
	if (sphere_hit(camera, obj, &tneark) && tneark < *tnear && tneark > 0.0001f)
	{
		*tnear = tneark;
		*hitobject = obj;
	}
}

void	plan_tape(t_camera *camera, t_object *obj, float *tnear,
		t_object **hitobject)
{
	float	tneark;

	tneark = MAXFLOAT;
	if (plan_hit(camera, obj, &tneark) && tneark < *tnear && tneark > 0.0001f)
	{
		*tnear = tneark;
		*hitobject = obj;
	}
}

void	cylinder_tape(t_camera *camera, t_object *obj, float *tnear,
		t_object **hitobject)
{
	float		tneark;

	tneark = MAXFLOAT;
	if (cylinder_hit(camera, obj, &tneark) && tneark <
			*tnear && tneark > 0.0001f)
	{
		*tnear = tneark;
		*hitobject = obj;
	}
}

void	triangle_tape(t_camera *camera, t_object *obj, float *tnear,
	t_object **hitobject)
{
	float		tneark;

	tneark = MAXFLOAT;
	if (triangle_hit(camera, obj, &tneark) && tneark <
			*tnear && tneark > 0.0001f)
	{
		*tnear = tneark;
		*hitobject = obj;
	}
}

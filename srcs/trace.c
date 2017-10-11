/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:21:15 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 20:55:34 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int			trace(t_camera *camera, t_object *obj, t_object **hitobject,
				float *tnear)
{
	*hitobject = NULL;
	*tnear = MAXFLOAT;
	while (obj)
	{
		if (obj->type == 1 || obj->type == 5)
			sphere_tape(camera, obj, tnear, hitobject);
		else if (obj->type == 2)
			plan_tape(camera, obj, tnear, hitobject);
		else if (obj->type == 3)
			cone_tape(camera, obj, tnear, hitobject);
		else if (obj->type == 4)
			cylinder_tape(camera, obj, tnear, hitobject);
		else if (obj->type == 6)
			torus_tape(camera, obj, tnear, hitobject);
		else if (obj->type == 7)
			triangle_tape(camera, obj, tnear, hitobject);
		obj = obj->next;
	}
	return (hitobject != NULL);
}

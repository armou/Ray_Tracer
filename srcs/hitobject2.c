/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitobject2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 19:29:21 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 20:56:16 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	torus_tape(t_camera *camera, t_object *obj, float *tnear,
	t_object **hitobject)
{
	float		tneark;

	tneark = MAXFLOAT;
	if (torus_hit(camera, obj, &tneark) && tneark <
			*tnear && tneark > 0.0001f)
	{
		*tnear = tneark;
		*hitobject = obj;
	}
}

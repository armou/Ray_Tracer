/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayhit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:36:01 by David             #+#    #+#             */
/*   Updated: 2017/10/05 20:55:37 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	triangle_assign(t_camera *cam, t_object *tle, t_pos e[2], t_pos p[0])
{
	e[0] = vector_sub(&tle->rot, &tle->origin);
	e[1] = vector_sub(&tle->trois, &tle->origin);
	p[0] = vector_cross(&cam->dir, &e[1]);
}

int		triangle_hit(t_camera *cam, t_object *tle, float *t)
{
	t_pos	e[2];
	t_pos	p[2];
	t_pos	v;
	float	inv;
	float	det;

	triangle_assign(cam, tle, e, p);
	det = vector_dot(&e[0], &p[0]);
	if (det > -0.000001 && det < 0.000001)
		return (0);
	inv = 1.0f / det;
	p[1] = vector_sub(&cam->origin, &tle->origin);
	v.x = vector_dot(&p[1], &p[0]) * inv;
	if (v.x < 0 || v.x > 1)
		return (0);
	p[1] = vector_cross(&p[1], &e[0]);
	v.y = vector_dot(&cam->dir, &p[1]) * inv;
	if (v.y < 0 || v.x + v.y > 1)
		return (0);
	if ((v.z = vector_dot(&e[1], &p[1]) * inv) > 0)
	{
		*t = v.z;
		return (1);
	}
	return (0);
}

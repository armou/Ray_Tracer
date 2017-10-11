/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayhit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:12:34 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/05 20:55:38 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int			ray_dist(float discr, float b, float *t, float a)
{
	float		sqrtdiscr;
	float		t0;
	float		t1;

	sqrtdiscr = sqrtf(discr);
	t0 = (-b + sqrtdiscr) / (2 * a);
	t1 = (-b - sqrtdiscr) / (2 * a);
	if (t0 > t1)
		t0 = t1;
	*t = t0;
	return (1);
}

int			sphere_hit(t_camera *cam, t_object *sp, float *t)
{
	float		a;
	float		b;
	float		c;
	float		discr;
	t_pos		dist;

	a = vector_dot(&cam->dir, &cam->dir);
	dist = vector_sub(&cam->origin, &sp->origin);
	b = 2 * vector_dot(&cam->dir, &dist);
	c = vector_dot(&dist, &dist) - (sp->size * sp->size);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	return (ray_dist(discr, b, t, a));
}

int			plan_hit(t_camera *cam, t_object *pl, float *t)
{
	t_pos		point;
	t_pos		m;
	t_pos		p;

	*t = (vector_dot(&pl->rot, &pl->origin) -
			vector_dot(&pl->rot, &cam->origin)) /
			vector_dot(&pl->rot, &cam->dir);
	if (*t < 0.0001)
		return (0);
	if (pl->size > 0)
	{
		point = vector_scale(&cam->dir, *t);
		point = vector_add(&cam->origin, &point);
		p = vector_add(&pl->origin, &(t_pos){pl->size * 0.5, pl->size\
				* 0.5, pl->size * 0.5});
		m = vector_sub(&pl->origin, &(t_pos){pl->size * 0.5, pl->size\
				* 0.5, pl->size * 0.5});
		if (point.x > p.x || point.x < m.x || point.y > p.y ||\
				point.y < m.y || point.z > p.z || point.z < m.z)
			return (0);
	}
	return (1);
}

int			cone_hit(t_camera *cam, t_object *co, float *t)
{
	double		disc;
	t_pos		dist;
	double		a;
	double		b;
	double		c;

	dist = vector_sub(&cam->origin, &co->origin);
	vector_norm(&co->rot);
	a = vector_dot(&cam->dir, &cam->dir) - (1 + pow(tan(co->size), 2)) *
		pow(vector_dot(&cam->dir, &co->rot), 2);
	b = 2 * (vector_dot(&cam->dir, &dist) - (1 + pow(tan(co->size), 2)) *
			vector_dot(&cam->dir, &co->rot) * vector_dot(&dist, &co->rot));
	c = vector_dot(&dist, &dist) - (1 + pow(tan(co->size), 2)) *
		pow(vector_dot(&dist, &co->rot), 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (0);
	return (ray_dist(disc, b, t, a));
}

int			cylinder_hit(t_camera *cam, t_object *cyl, float *t)
{
	float		a;
	float		b;
	float		c;
	float		discr;
	t_pos		dist;

	dist = vector_sub(&cam->origin, &cyl->origin);
	vector_norm(&cyl->rot);
	a = vector_dot(&cam->dir, &cam->dir) -
		pow(vector_dot(&cam->dir, &cyl->rot), 2);
	b = 2 * (vector_dot(&cam->dir, &dist) - (vector_dot(&cam->dir, &cyl->rot) *
				vector_dot(&dist, &cyl->rot)));
	c = vector_dot(&dist, &dist) - pow(vector_dot(&dist, &cyl->rot), 2) -
		pow(cyl->size, 2);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	return (ray_dist(discr, b, t, a));
}

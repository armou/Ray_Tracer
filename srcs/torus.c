/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:12:34 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/05 20:55:35 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

float			check_ret(double *ret)
{
	int			i;
	float		root;
	float		root_rend;

	i = -1;
	root_rend = 0;
	while (++i < 4)
	{
		root = ret[i];
		if (root > -1 && (root_rend == 0 || root < root_rend))
			root_rend = root;
	}
	return (root_rend);
}

void			torus_hit2(t_camera *cam, t_object *tor, t_torus *torus)
{
	torus->i = -1;
	vector_norm(&tor->rot);
	torus->dist = vector_sub(&cam->origin, &tor->origin);
	torus->n = vector_dot(&cam->dir, &torus->dist);
	torus->det = torus->n > 0.5 ? 0 : 1;
	torus->o = vector_dot(&torus->dist, &torus->dist);
	torus->q = vector_dot(&tor->rot, &torus->dist);
	torus->m = vector_dot(&torus->dist, &cam->dir);
	torus->p = vector_dot(&tor->rot, &cam->dir);
}

int				torus_hit(t_camera *cam, t_object *tor, float *t)
{
	t_torus		torus;
	t_5pow		zz;
	double		ret[4];

	torus_hit2(cam, tor, &torus);
	torus.r1 = pow(tor->size, 2);
	torus.r2 = pow(tor->b_size, 2);
	torus.a = 1 - pow(torus.p, 2);
	torus.b = 2 * (torus.m - torus.q * torus.p);
	torus.c = torus.o - pow(torus.q, 2);
	torus.d = torus.o + torus.r2 - torus.r1;
	zz.q4 = 1;
	zz.q3 = 4 * torus.n;
	zz.q2 = 2 * torus.d + zz.q3 * zz.q3 * 0.25 - 4 * torus.r2 * torus.a;
	zz.q1 = zz.q3 * torus.d - 4 * torus.r2 * torus.b;
	zz.q0 = torus.d * torus.d - 4 * torus.r2 * torus.c;
	while (++torus.i < 4)
		ret[torus.i] = -1;
	if (torus.det && (quartic_solver(ret, zz)))
		if ((*t = check_ret(ret)))
			return (1);
	return (0);
}

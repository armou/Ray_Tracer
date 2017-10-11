/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:12:34 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/05 20:57:07 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		solve_1(t_cub_sol sol, t_4pow *x, int *nr)
{
	float s1;
	float s2;

	s1 = sol.r + sqrt(sol.d);
	s2 = sol.r - sqrt(sol.d);
	s1 = (s1 >= 0.0) ? pow(s1, 1. / 3.) : -pow(-s1, 1. / 3.);
	s2 = (s2 >= 0.0) ? pow(s2, 1. / 3.) : -pow(-s2, 1. / 3.);
	x->q1 = (s1 + s2) - sol.a.q2 / 3.0;
	x->q2 = -0.5 * (s1 + s2) - sol.a.q2 / 3.0;
	x->q3 = x->q2;
	*nr = 1;
}

void		solve_2(t_cub_sol sol, t_4pow *x, int *nr)
{
	float theta;
	float costh;
	float sinth;
	float sq;

	theta = acos(sol.r / sqrt(-sol.q * sol.q * sol.q)) / 3.0;
	costh = cos(theta);
	sinth = sin(theta);
	sq = sqrt(-sol.q);
	x->q1 = 2.0 * sq * costh - sol.a.q2 / 3.0;
	x->q2 = -sq * costh - sol.a.q2 / 3.0 - sqrt(3.) * sq * sinth;
	x->q3 = -sq * costh - sol.a.q2 / 3.0 + sqrt(3.) * sq * sinth;
	*nr = 3;
}

void		cubic_equation(t_4pow c, t_4pow *x, int *nr)
{
	t_cub_sol	sol;
	float		s;

	sol.a.q2 = c.q2 / c.q3;
	sol.a.q1 = c.q1 / c.q3;
	sol.a.q0 = c.q0 / c.q3;
	sol.q = sol.a.q1 / 3.0 - pow(sol.a.q2, 2) / 9.0;
	sol.r = (sol.a.q1 * sol.a.q2 - 3.0 * sol.a.q0) / 6.0 - \
			pow(sol.a.q2, 3) / 27.0;
	sol.d = pow(sol.q, 3) + pow(sol.r, 2);
	if (sol.d > 0.0)
		solve_1(sol, x, nr);
	else if (sol.d < 0.0)
		solve_2(sol, x, nr);
	else
	{
		s = (sol.r >= 0.0) ? pow(sol.r, 1. / 3.) : -pow(-sol.r, 1. / 3.);
		x->q1 = 2.0 * s - sol.a.q2 / 3.0;
		x->q2 = -s - sol.a.q2 / 3.0;
		x->q3 = x->q2;
		*nr = 3;
	}
}

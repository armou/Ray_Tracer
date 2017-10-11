/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 14:31:56 by daugier           #+#    #+#             */
/*   Updated: 2017/10/05 19:51:45 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUARTIC_H
# define QUARTIC_H

# include <math.h>
# include <stdlib.h>
# include <time.h>

# define R 	sol.ret1
# define R2 sol.ret2
# define R3 sol.ret3
# define R4 sol->ret4
# define R5 sol.ret5
# define R6 sol->ret6
# define R7 sol.ret7
# define TA sol->a
# define AL sol->alpha

typedef struct	s_5pow
{
	double		q3;
	double		q2;
	double		q1;
	double		q0;
	double		q4;
}				t_5pow;

typedef struct	s_4pow
{
	double		q3;
	double		q2;
	double		q1;
	double		q0;
}				t_4pow;

typedef struct	s_3pow
{
	double		q2;
	double		q1;
	double		q0;
}				t_3pow;

typedef struct	s_cub_sol
{
	t_3pow		a;
	double		q;
	double		r;
	double		d;
}				t_cub_sol;

typedef struct	s_quartic_sol
{
	t_5pow		r;
	int			alpha;
	int			beta;
	t_4pow		a;
	t_4pow		new_a;
	t_4pow		x;
	int			nbr;
	int			useless;
	double		ret1;
	double		ret2;
	double		ret3;
	double		ret4;
	double		ret5;
	double		ret6;
	double		ret7;
	double		f1;
	double		f2;
}				t_quartic_sol;

typedef struct	s_torus
{
	float		r1;
	float		r2;
	float		a;
	float		b;
	float		c;
	float		d;
	float		m;
	float		n;
	float		o;
	float		p;
	float		q;
	int			i;
	t_pos		dist;
	int			det;
}				t_torus;

void			cubic_equation(t_4pow c, t_4pow *x, int *nr);
int				quartic_solver(double *ret, t_5pow d);

#endif

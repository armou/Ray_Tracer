/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:00:46 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/05 20:24:36 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_pos
{
	cl_double		x;
	cl_double		y;
	cl_double		z;
}				t_pos;

t_pos			vector_reflect(t_pos *v1, t_pos *v2);
void			vector_focale(t_pos *c);
void			vector_norm(t_pos *c);
t_pos			vector_cross(t_pos *v1, t_pos *v2);
t_pos			vector_add(t_pos *v1, t_pos *v2);
t_pos			vector_sub(t_pos *v1, t_pos *v2);
float			vector_dot(t_pos *v1, t_pos *v2);
t_pos			vector_scale(t_pos *v1, float c);

#endif

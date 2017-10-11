/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 19:44:02 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/05 20:56:55 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void		vector_norm(t_pos *c)
{
	float	norm;

	norm = sqrtf(c->x * c->x + c->y * c->y + c->z * c->z);
	norm < 0.0f ? norm *= -1 : 0;
	c->x /= norm;
	c->y /= norm;
	c->z /= norm;
}

t_pos		vector_cross(t_pos *v1, t_pos *v2)
{
	t_pos	result;

	result.x = v1->y * v2->z - v1->z * v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;
	return (result);
}

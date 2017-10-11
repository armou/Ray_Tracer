/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:49:49 by aoudin            #+#    #+#             */
/*   Updated: 2017/10/05 20:56:59 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

t_pos		vector_sub(t_pos *v1, t_pos *v2)
{
	t_pos	result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

float		vector_dot(t_pos *v1, t_pos *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_pos		vector_scale(t_pos *v1, float c)
{
	t_pos	result;

	result.x = v1->x * c;
	result.y = v1->y * c;
	result.z = v1->z * c;
	return (result);
}

t_pos		vector_mult(t_pos *v1, t_pos *v2)
{
	t_pos	result;

	result.x = v1->x * v2->x;
	result.y = v1->y * v2->y;
	result.z = v1->z * v2->z;
	return (result);
}

t_pos		vector_add(t_pos *v1, t_pos *v2)
{
	t_pos	result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

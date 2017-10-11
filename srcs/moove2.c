/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 07:14:37 by David             #+#    #+#             */
/*   Updated: 2017/10/05 20:56:38 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	cam_move_front(t_rt *rtv1)
{
	if (MOOVE & FRONT)
	{
		if (rtv1->tmp_obj)
		{
			if (rtv1->tmp_obj->type == 7 || rtv1->tmp_obj->type == 8)
				modif_float(&rtv1->tmp_obj->origin.y, &rtv1->tmp_obj->trois.y,\
						&rtv1->tmp_obj->rot.y, STEP_MOVE_OBJ);
			else
				rtv1->tmp_obj->origin.y += STEP_MOVE_OBJ;
		}
		else
			rtv1->camera.origin.y += STEP_MOVE_CAM;
	}
}

void	cam_move_walk(t_rt *rtv1)
{
	if (MOOVE & WALK)
	{
		if (rtv1->tmp_obj)
		{
			if (rtv1->tmp_obj->type == 7 || rtv1->tmp_obj->type == 8)
				modif_float(&rtv1->tmp_obj->origin.z, &rtv1->tmp_obj->trois.z,\
						&rtv1->tmp_obj->rot.z, -STEP_MOVE_OBJ);
			else
				rtv1->tmp_obj->origin.z -= STEP_MOVE_OBJ;
		}
		else
		{
			rtv1->lol = ray_for_move(rtv1);
			rtv1->lol.rot.z = rtv1->camera.rot.z;
			rotate_xx(&rtv1->lol);
			rotate_yy(&rtv1->lol);
			rotate_zz(&rtv1->lol);
			vector_norm(&rtv1->lol.dir);
			rtv1->lol.dir = vector_scale(&rtv1->lol.dir, STEP_MOVE_CAM);
			rtv1->camera.origin = vector_add(&rtv1->camera.origin,\
					&rtv1->lol.dir);
		}
	}
}

void	cam_move_back(t_rt *rtv1)
{
	if (MOOVE & BACK)
	{
		if (rtv1->tmp_obj)
		{
			if (rtv1->tmp_obj->type == 7 || rtv1->tmp_obj->type == 8)
				modif_float(&rtv1->tmp_obj->origin.y, &rtv1->tmp_obj->trois.y,\
						&rtv1->tmp_obj->rot.y, -STEP_MOVE_OBJ);
			else
				rtv1->tmp_obj->origin.y -= STEP_MOVE_OBJ;
		}
		else
			rtv1->camera.origin.y -= STEP_MOVE_CAM;
	}
}

void	cam_move_dewalk(t_rt *rtv1)
{
	if (MOOVE & DEWALK)
	{
		if (rtv1->tmp_obj)
		{
			if (rtv1->tmp_obj->type == 7 || rtv1->tmp_obj->type == 8)
				modif_float(&rtv1->tmp_obj->origin.z, &rtv1->tmp_obj->trois.z,\
						&rtv1->tmp_obj->rot.z, STEP_MOVE_OBJ);
			else
				rtv1->tmp_obj->origin.z += STEP_MOVE_OBJ;
		}
		else
		{
			rtv1->lol = ray_for_move(rtv1);
			rtv1->lol.rot.z = rtv1->camera.rot.z;
			rotate_xx(&rtv1->lol);
			rotate_yy(&rtv1->lol);
			rotate_zz(&rtv1->lol);
			vector_norm(&rtv1->lol.dir);
			rtv1->lol.dir = vector_scale(&rtv1->lol.dir, STEP_MOVE_CAM);
			rtv1->camera.origin = vector_sub(&rtv1->camera.origin,\
					&rtv1->lol.dir);
		}
	}
}

void	cam_move_left(t_rt *rtv1)
{
	if (MOOVE & LEFT)
	{
		if (rtv1->tmp_obj)
		{
			if (rtv1->tmp_obj->type == 7 || rtv1->tmp_obj->type == 8)
				modif_float(&rtv1->tmp_obj->origin.x, &rtv1->tmp_obj->trois.x,\
						&rtv1->tmp_obj->rot.x, -STEP_MOVE_OBJ);
			else
				rtv1->tmp_obj->origin.x -= STEP_MOVE_OBJ;
		}
		else
		{
			rtv1->lol = ray_for_move(rtv1);
			rtv1->lol.rot.y = rtv1->camera.rot.y + 5;
			if (fabs(rtv1->lol.rot.x) > fabs(rtv1->lol.rot.y))
				rtv1->lol.rot.z = 1 - rtv1->lol.rot.x;
			else
				rtv1->lol.rot.z = 1 - rtv1->lol.rot.y;
			rotate_yy(&rtv1->lol);
			vector_norm(&rtv1->lol.dir);
			rtv1->lol.dir = vector_scale(&rtv1->lol.dir, STEP_MOVE_CAM);
			rtv1->camera.origin = vector_add(&rtv1->camera.origin,\
					&rtv1->lol.dir);
		}
	}
}

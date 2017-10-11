/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:18:26 by daugier           #+#    #+#             */
/*   Updated: 2017/10/05 20:57:05 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	modif_float(double *a, double *b, double *c, double step)
{
	*a += step;
	*b += step;
	*c += step;
}

void	cam_move_right(t_rt *rtv1)
{
	if (MOOVE & RIGHT)
	{
		if (rtv1->tmp_obj)
		{
			if (rtv1->tmp_obj->type == 7 || rtv1->tmp_obj->type == 8)
				modif_float(&rtv1->tmp_obj->origin.x, &rtv1->tmp_obj->trois.x,\
						&rtv1->tmp_obj->rot.x, STEP_MOVE_OBJ);
			else
				rtv1->tmp_obj->origin.x += STEP_MOVE_OBJ;
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
			rtv1->camera.origin = vector_sub(&rtv1->camera.origin,\
					&rtv1->lol.dir);
		}
	}
}

void	rot_move2(t_rt *rtv1)
{
	if (MOOVE & ROT_RIGHT)
	{
		if (rtv1->tmp_obj && rtv1->tmp_obj->type != 7\
				&& rtv1->tmp_obj->type != 8)
			rtv1->tmp_obj->rot = rot_obj(rtv1->tmp_obj->rot,\
				(t_pos){0, FOV, 0});
		else
			rtv1->camera.rot.y -= STEP_ROT_CAM;
	}
	if (MOOVE & ROT_BOT)
	{
		if (rtv1->tmp_obj && rtv1->tmp_obj->type != 7\
				&& rtv1->tmp_obj->type != 8)
			rtv1->tmp_obj->rot = rot_obj(rtv1->tmp_obj->rot,\
				(t_pos){FOV, 0, 0});
		else
			rtv1->camera.rot.x -= STEP_ROT_CAM;
	}
}

void	rot_move(t_rt *rtv1)
{
	if (MOOVE & ROT_LEFT)
	{
		if (rtv1->tmp_obj && rtv1->tmp_obj->type != 7\
				&& rtv1->tmp_obj->type != 8)
			rtv1->tmp_obj->rot = rot_obj(rtv1->tmp_obj->rot,\
				(t_pos){0, -FOV, 0});
		else
			rtv1->camera.rot.y += STEP_ROT_CAM;
	}
	if (MOOVE & ROT_TOP)
	{
		if (rtv1->tmp_obj && rtv1->tmp_obj->type != 7\
				&& rtv1->tmp_obj->type != 8)
			rtv1->tmp_obj->rot = rot_obj(rtv1->tmp_obj->rot,\
				(t_pos){-FOV, 0, 0});
		else
			rtv1->camera.rot.x += STEP_ROT_CAM;
	}
}

void	ft_moove(t_rt *rtv1)
{
	cam_move_front(rtv1);
	cam_move_walk(rtv1);
	cam_move_back(rtv1);
	cam_move_dewalk(rtv1);
	cam_move_left(rtv1);
	cam_move_right(rtv1);
	rot_move(rtv1);
	rot_move2(rtv1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:44:11 by David             #+#    #+#             */
/*   Updated: 2017/10/05 20:56:39 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

t_pos		rot_obj(t_pos vec, t_pos rot)
{
	t_pos	b;

	b.x = vec.x * cos(rot.z * M_PI_2 * 0.0005f) - vec.y *\
	sin(rot.z * M_PI_2 * 0.0005f);
	b.y = vec.x * sin(rot.z * M_PI_2 * 0.0005f) + vec.y *\
	cos(rot.z * M_PI_2 * 0.0005f);
	b.z = vec.z;
	vec = b;
	b.y = vec.y * cos(rot.y * M_PI_2 * 0.0005f) - vec.z *\
	sin(rot.y * M_PI_2 * 0.0005f);
	b.z = vec.y * sin(rot.y * M_PI_2 * 0.0005f) + vec.z *\
	cos(rot.y * M_PI_2 * 0.0005f);
	b.x = vec.x;
	vec = b;
	b.z = vec.z * cos(rot.x * M_PI_2 * 0.0005f) - vec.x *\
	sin(rot.x * M_PI_2 * 0.0005f);
	b.x = vec.z * sin(rot.x * M_PI_2 * 0.0005f) + vec.x *\
	cos(rot.x * M_PI_2 * 0.0005f);
	b.y = vec.y;
	return (b);
}

void		rotate_xx(t_camera *camera)
{
	double	y_tmp;
	double	z_tmp;
	double	angle;

	angle = DEG_TO_RAD(camera->rot.x);
	y_tmp = camera->dir.y;
	z_tmp = camera->dir.z;
	camera->dir.y = y_tmp * cos(angle) - z_tmp * sin(angle);
	camera->dir.z = y_tmp * sin(angle) + z_tmp * cos(angle);
}

void		rotate_yy(t_camera *camera)
{
	double	x_tmp;
	double	z_tmp;
	double	angle;

	angle = DEG_TO_RAD(camera->rot.y);
	x_tmp = camera->dir.x;
	z_tmp = camera->dir.z;
	camera->dir.z = z_tmp * cos(angle) - x_tmp * sin(angle);
	camera->dir.x = z_tmp * sin(angle) + x_tmp * cos(angle);
}

void		rotate_zz(t_camera *camera)
{
	double	x_tmp;
	double	y_tmp;
	double	angle;

	angle = DEG_TO_RAD(camera->rot.z);
	x_tmp = camera->dir.x;
	y_tmp = camera->dir.y;
	camera->dir.x = x_tmp * cos(angle) - y_tmp * sin(angle);
	camera->dir.y = x_tmp * sin(angle) + y_tmp * cos(angle);
}

t_camera	ray_for_move(t_rt *rtv1)
{
	float	angle;
	float	inv_width;
	float	inv_height;
	float	aspectratio;

	inv_width = 1 / (float)(WIDTH);
	inv_height = 1 / (float)(HEIGHT);
	aspectratio = (float)(WIDTH) / (float)(HEIGHT);
	angle = tan((M_PI * 0.5f) / 180.0f);
	rtv1->lol.dir.x = (2.0f * ((0 + 0.5f) * inv_width) - 1.0f) * angle *
		aspectratio;
	rtv1->lol.dir.y = (1.0f - 2.0f * ((0 + 0.5f) * inv_height)) * angle;
	rtv1->lol.dir.z = -1.0f;
	rtv1->lol.rot.x = rtv1->camera.rot.x;
	rtv1->lol.rot.y = rtv1->camera.rot.y;
	return (rtv1->lol);
}

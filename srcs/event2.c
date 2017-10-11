/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 07:27:38 by David             #+#    #+#             */
/*   Updated: 2017/10/05 20:56:26 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	event_antialiasing(t_rt *rtv1)
{
	if (rtv1->event.key.keysym.sym == SDLK_l)
	{
		rtv1->aliasing < 4 ? rtv1->aliasing++ : 0;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
	if (rtv1->event.key.keysym.sym == SDLK_k)
	{
		rtv1->aliasing > 1 ? rtv1->aliasing-- : 0;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
}

void	event_mouse(t_rt *rtv1)
{
	if (rtv1->event.button.button == SDL_BUTTON_LEFT)
	{
		rtv1->camera.dir.x = (2 * ((rtv1->event.button.x + 0.5) /\
					(float)WIDTH) - 1) * ANGLE * ASPECTRATIO;
		rtv1->camera.dir.y = (1 - 2 * ((rtv1->event.button.y + 0.5)\
					/ HEIGHT)) * ANGLE;
		rtv1->camera.dir.z = -1;
		rotate_x(rtv1);
		rotate_y(rtv1);
		rotate_z(rtv1);
		vector_norm(&rtv1->camera.dir);
		trace(&rtv1->camera, rtv1->object, &rtv1->tmp_obj, &rtv1->t);
	}
	if (rtv1->event.button.button == SDL_BUTTON_RIGHT)
		rtv1->tmp_obj = NULL;
}

void	event_moove_up(t_rt *rtv1)
{
	if (rtv1->event.key.keysym.sym == SDLK_LEFT)
		MOOVE ^= LEFT;
	if (rtv1->event.key.keysym.sym == SDLK_RIGHT)
		MOOVE ^= RIGHT;
	if (rtv1->event.key.keysym.sym == SDLK_UP)
		MOOVE ^= WALK;
	if (rtv1->event.key.keysym.sym == SDLK_DOWN)
		MOOVE ^= DEWALK;
	if (rtv1->event.key.keysym.sym == SDLK_RSHIFT ||\
			rtv1->event.key.keysym.sym == SDLK_PAGEUP)
		MOOVE ^= FRONT;
	if (rtv1->event.key.keysym.sym == SDLK_SLASH ||\
			rtv1->event.key.keysym.sym == SDLK_PAGEDOWN)
		MOOVE ^= BACK;
	if (rtv1->event.key.keysym.sym == SDLK_w)
		MOOVE ^= ROT_TOP;
	if (rtv1->event.key.keysym.sym == SDLK_s)
		MOOVE ^= ROT_BOT;
	if (rtv1->event.key.keysym.sym == SDLK_a)
		MOOVE ^= ROT_LEFT;
	if (rtv1->event.key.keysym.sym == SDLK_d)
		MOOVE ^= ROT_RIGHT;
}

void	event_moove_down(t_rt *rtv1)
{
	if (rtv1->event.key.keysym.sym == SDLK_LEFT)
		MOOVE |= LEFT;
	if (rtv1->event.key.keysym.sym == SDLK_RIGHT)
		MOOVE |= RIGHT;
	if (rtv1->event.key.keysym.sym == SDLK_UP)
		MOOVE |= WALK;
	if (rtv1->event.key.keysym.sym == SDLK_DOWN)
		MOOVE |= DEWALK;
	if (rtv1->event.key.keysym.sym == SDLK_PAGEUP)
		MOOVE |= FRONT;
	if (rtv1->event.key.keysym.sym == SDLK_DOWN)
		MOOVE |= DEWALK;
	if (rtv1->event.key.keysym.sym == SDLK_RSHIFT)
		MOOVE |= FRONT;
	if (rtv1->event.key.keysym.sym == SDLK_PAGEDOWN)
		MOOVE |= BACK;
	if (rtv1->event.key.keysym.sym == SDLK_w)
		MOOVE |= ROT_TOP;
	if (rtv1->event.key.keysym.sym == SDLK_s)
		MOOVE |= ROT_BOT;
	if (rtv1->event.key.keysym.sym == SDLK_a)
		MOOVE |= ROT_LEFT;
	if (rtv1->event.key.keysym.sym == SDLK_d)
		MOOVE |= ROT_RIGHT;
}

void	event_add_obj(t_rt *rtv1)
{
	if (rtv1->nb_object + 1 < 300)
	{
		if (rtv1->event.key.keysym.sym == SDLK_i)
			add_sphere(rtv1);
		if (rtv1->event.key.keysym.sym == SDLK_u)
			add_torus(rtv1);
		if (rtv1->event.key.keysym.sym == SDLK_y)
			add_plan(rtv1);
		if (rtv1->event.key.keysym.sym == SDLK_t)
			add_light(rtv1);
		if (rtv1->event.key.keysym.sym == SDLK_r)
			add_triangle(rtv1);
		if (rtv1->event.key.keysym.sym == SDLK_e)
			add_alter(rtv1);
	}
}

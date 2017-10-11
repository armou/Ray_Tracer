/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:38:56 by David             #+#    #+#             */
/*   Updated: 2017/10/05 22:56:28 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	event_obj(t_rt *rtv1)
{
	if (rtv1->tmp_obj)
	{
		if ((rtv1->event.key.keysym.sym == SDLK_DELETE ||\
					rtv1->event.key.keysym.sym == SDLK_BACKSPACE))
		{
			del_object(rtv1);
			rtv1->offset_x = 0;
			rtv1->offset_y = 0;
		}
		if (rtv1->event.key.keysym.sym == SDLK_EQUALS ||\
				rtv1->event.key.keysym.sym == SDLK_KP_PLUS)
		{
			rtv1->tmp_obj->size += STEP_SIZE_UPDOWN;
			rtv1->offset_x = 0;
			rtv1->offset_y = 0;
		}
		if (rtv1->event.key.keysym.sym == SDLK_LEFTBRACKET ||\
				rtv1->event.key.keysym.sym == SDLK_KP_DIVIDE)
		{
			rtv1->tmp_obj->b_size += STEP_SIZE_UPDOWN;
			rtv1->offset_x = 0;
			rtv1->offset_y = 0;
		}
	}
}

void	event_change_scene2(t_rt *rtv1)
{
	if (rtv1->event.key.keysym.sym == SDLK_1)
	{
		free_list(rtv1->object);
		rtv1->tmp_obj = NULL;
		if (!(stock_object("scene/avion.xml", rtv1)))
			exit(EXIT_SUCCESS);
		init_param(rtv1);
	}
	if (rtv1->event.key.keysym.sym == SDLK_5)
	{
		free_list(rtv1->object);
		rtv1->tmp_obj = NULL;
		if (!(stock_object("scene/scene11.xml", rtv1)))
			exit(EXIT_SUCCESS);
		init_param(rtv1);
	}
}

void	event_change_scene(t_rt *rtv1)
{
	if (rtv1->event.key.keysym.sym == SDLK_4)
	{
		free_list(rtv1->object);
		rtv1->tmp_obj = NULL;
		if (!(stock_object("scene/scene12.xml", rtv1)))
			exit(EXIT_SUCCESS);
		init_param(rtv1);
	}
	if (rtv1->event.key.keysym.sym == SDLK_3)
	{
		free_list(rtv1->object);
		rtv1->tmp_obj = NULL;
		if (!(stock_object("scene/scene7.xml", rtv1)))
			exit(EXIT_SUCCESS);
		init_param(rtv1);
	}
	if (rtv1->event.key.keysym.sym == SDLK_2)
	{
		free_list(rtv1->object);
		rtv1->tmp_obj = NULL;
		if (!(stock_object("scene/scene9.xml", rtv1)))
			exit(EXIT_SUCCESS);
		init_param(rtv1);
	}
}

void	event_rt(t_rt *rtv1)
{
	if (rtv1->event.window.event == SDL_WINDOWEVENT_CLOSE || (rtv1->event.type\
		== SDL_KEYDOWN && rtv1->event.key.keysym.sym == SDLK_ESCAPE))
		rtv1->run = 0;
	if (rtv1->event.type == SDL_KEYUP)
		event_moove_up(rtv1);
	if (rtv1->event.type == SDL_KEYDOWN)
	{
		event_moove_down(rtv1);
		event_antialiasing(rtv1);
		event_change_scene(rtv1);
		event_change_scene2(rtv1);
		event_add_obj(rtv1);
		event_effect(rtv1);
		event_screenshot(rtv1, 0);
		event_change_rgb(rtv1);
		event_obj(rtv1);
		event_obj2(rtv1);
		event_affichagedumal(rtv1);
		event_cam_ori(rtv1);
	}
	if (rtv1->event.type == SDL_MOUSEBUTTONDOWN)
		event_mouse(rtv1);
}

int		del_list_event(void *data, SDL_Event *event)
{
	t_rt *rtv1;

	rtv1 = (t_rt*)data;
	if (event->type == SDL_KEYUP)
		SDL_FlushEvent(SDL_KEYDOWN);
	if (event->type == SDL_MOUSEBUTTONUP)
		SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
	return (1);
}

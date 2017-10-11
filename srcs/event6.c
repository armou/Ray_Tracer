/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:38:56 by David             #+#    #+#             */
/*   Updated: 2017/10/05 22:15:19 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	free_list(t_object *list)
{
	t_object *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	list = NULL;
}

void	del_object(t_rt *rtv1)
{
	t_object *cpy;
	t_object *tmp;

	cpy = rtv1->object;
	if (cpy->number == rtv1->tmp_obj->number)
	{
		rtv1->object = cpy->next;
		free(cpy);
	}
	else
	{
		tmp = cpy->next;
		while (tmp)
		{
			if (tmp->number == rtv1->tmp_obj->number)
			{
				cpy->next = tmp->next;
				free(tmp);
				break ;
			}
			cpy = tmp;
			tmp = tmp->next;
		}
	}
	rtv1->tmp_obj = NULL;
}

void	event_obj2(t_rt *rtv1)
{
	if (rtv1->tmp_obj)
	{
		if ((rtv1->event.key.keysym.sym == SDLK_MINUS ||\
			rtv1->event.key.keysym.sym == SDLK_KP_MINUS))
			if (rtv1->tmp_obj->size - STEP_SIZE_UPDOWN > 0.01)
			{
				rtv1->tmp_obj->size -= STEP_SIZE_UPDOWN;
				rtv1->offset_x = 0;
				rtv1->offset_y = 0;
			}
		if (rtv1->event.key.keysym.sym == SDLK_RIGHTBRACKET ||\
			rtv1->event.key.keysym.sym == SDLK_KP_MULTIPLY)
			if (rtv1->tmp_obj->b_size - STEP_SIZE_UPDOWN > 0.01)
			{
				rtv1->tmp_obj->b_size -= STEP_SIZE_UPDOWN;
				rtv1->offset_x = 0;
				rtv1->offset_y = 0;
			}
	}
}

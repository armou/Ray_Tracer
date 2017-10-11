/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:07:19 by David             #+#    #+#             */
/*   Updated: 2017/10/05 23:06:46 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	event_change_rgb(t_rt *rtv1)
{
	if (rtv1->event.key.keysym.sym == SDLK_x && rtv1->tmp_obj)
	{
		rtv1->tmp_obj->color.r = (rtv1->tmp_obj->color.r + 0.05) <= 1\
			? rtv1->tmp_obj->color.r + 0.05 : 0;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
	if (rtv1->event.key.keysym.sym == SDLK_c && rtv1->tmp_obj)
	{
		rtv1->tmp_obj->color.g = (rtv1->tmp_obj->color.g + 0.05) <= 1\
			? rtv1->tmp_obj->color.g + 0.05 : 0;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
	if (rtv1->event.key.keysym.sym == SDLK_v && rtv1->tmp_obj)
	{
		rtv1->tmp_obj->color.b = (rtv1->tmp_obj->color.b + 0.05) <= 1\
			? rtv1->tmp_obj->color.b + 0.05 : 0;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
}

void	event_screenshot(t_rt *rtv1, int i)
{
	char	*file;
	FILE	*file_tmp;

	if (rtv1->event.key.keysym.sym == SDLK_o)
	{
		while (++i)
		{
			file = ft_strjoinfree(ft_itoa(i - 1), ".png");
			file = ft_strjoin("save_img/", file);
			file_tmp = fopen(file, "r");
			if (file_tmp)
				fclose(file_tmp);
			else
			{
				IMG_SavePNG(rtv1->screen, file);
				ft_printf("impress ok !\n");
				break ;
			}
			free(file);
		}
	}
}

void	event_effect(t_rt *rtv1)
{
	if (rtv1->event.key.keysym.sym == SDLK_m)
		rtv1->motion_blur == 1 ? rtv1->motion_blur-- : rtv1->motion_blur++;
	if (rtv1->event.key.keysym.sym == SDLK_n)
	{
		rtv1->density = (rtv1->density == 20) ? 0 : rtv1->density + 0.01;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
	if (rtv1->event.key.keysym.sym == SDLK_q)
	{
		rtv1->filter = (rtv1->filter == 7) ? 0 : rtv1->filter + 1;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
	if (rtv1->event.key.keysym.sym == SDLK_f && rtv1->tmp_obj)
	{
		rtv1->tmp_obj->texture = (rtv1->tmp_obj->texture == 11)\
			? 1 : rtv1->tmp_obj->texture + 1;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
}

void	event_cam_ori(t_rt *rtv1)
{
	if (rtv1->event.key.keysym.sym == SDLK_TAB)
	{
		rtv1->camera.origin = (t_pos){0.0f, 0.0f, 0.0f};
		rtv1->camera.rot = (t_pos){0.0f, 0.0f, 0.0f};
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
	if (rtv1->event.key.keysym.sym == SDLK_QUOTE)
	{
		rtv1->ambiante = (rtv1->ambiante + 0.1 <= 1) ? rtv1->ambiante + 0.1\
		: rtv1->ambiante;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
	if (rtv1->event.key.keysym.sym == SDLK_SEMICOLON)
	{
		rtv1->ambiante = (rtv1->ambiante - 0.1 > 0) ? rtv1->ambiante - 0.1 :\
		rtv1->ambiante;
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
}

void	event_affichagedumal(t_rt *rtv1)
{
	if (rtv1->event.key.keysym.sym == SDLK_z)
		if (rtv1->tmp_obj)
		{
			ft_printf("------------------------------------------\n");
			ft_printf("|             OBJECTS                    |\n");
			ft_printf("------------------------------------------\n");
			ft_printf("             Object : %d\n", rtv1->tmp_obj->number);
			ft_printf("           Type object : %d\n", rtv1->tmp_obj->type);
			ft_printf("           Size : %f\n", rtv1->tmp_obj->size);
			ft_printf("           Size2 : %f\n", rtv1->tmp_obj->b_size);
			ft_printf("            Origin x : %f\n", rtv1->tmp_obj->origin.x);
			ft_printf("            Origin y : %f\n", rtv1->tmp_obj->origin.y);
			ft_printf("            Origin z : %f\n", rtv1->tmp_obj->origin.z);
			ft_printf("           Rotation x : %f\n", rtv1->tmp_obj->rot.x);
			ft_printf("           Rotation y : %f\n", rtv1->tmp_obj->rot.y);
			ft_printf("           Rotation z : %f\n", rtv1->tmp_obj->rot.z);
			ft_printf("         Reflection : %f\n", rtv1->tmp_obj->reflection);
			ft_printf("           Color : %d\n", rtv1->tmp_obj->color);
			ft_printf("           Texture : %d\n", rtv1->tmp_obj->texture);
		}
}

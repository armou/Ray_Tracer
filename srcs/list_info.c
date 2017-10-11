/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 17:06:30 by daugier           #+#    #+#             */
/*   Updated: 2017/10/05 20:57:04 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void			list_comment(t_rt *rtv1)
{
	ft_printf("-------------------------------------------------\n");
	ft_printf("|                  COMMENTARY                   |\n");
	ft_printf("-------------------------------------------------\n");
	if (rtv1->comment[0] != '\0')
		ft_printf("        %s\n", rtv1->comment);
	else
		ft_printf("                  No commentary\n");
}

void			list_cam(t_rt *rtv1)
{
	ft_printf("-------------------------------------------------\n");
	ft_printf("|                    CAMERA                     |\n");
	ft_printf("-------------------------------------------------\n");
	ft_printf("                  Origin x : %f\n", rtv1->camera.origin.x);
	ft_printf("                  Origin y : %f\n", rtv1->camera.origin.y);
	ft_printf("                  Origin z : %f\n\n", rtv1->camera.origin.z);
	ft_printf("                 Rotation x : %f\n", rtv1->camera.rot.x);
	ft_printf("                 Rotation y : %f\n", rtv1->camera.rot.y);
	ft_printf("                 Rotation z : %f\n", rtv1->camera.rot.z);
}

void			list_object2(t_object *cpy, int i)
{
	ft_printf("                    Object : %d\n\n", i);
	ft_printf("                  Type object : %d\n\n", cpy->type);
	ft_printf("                   Origin x : %f\n", cpy->origin.x);
	ft_printf("                   Origin y : %f\n", cpy->origin.y);
	ft_printf("                   Origin z : %f\n\n", cpy->origin.z);
	ft_printf("                  Rotation x : %f\n", cpy->rot.x);
	ft_printf("                  Rotation y : %f\n", cpy->rot.y);
	ft_printf("                  Rotation z : %f\n\n", cpy->rot.z);
	ft_printf("                 Texture : %f\n\n", cpy->texture);
	ft_printf("                  Reflection : %f\n\n", cpy->reflection);
	ft_printf("                  Color : %d\n", cpy->color);
	ft_printf("                  Size : %f\n", cpy->size);
}

void			list_object(t_rt *rtv1)
{
	t_object	*cpy;
	int			i;

	i = 0;
	cpy = rtv1->object;
	ft_printf("-------------------------------------------------\n");
	ft_printf("|                    OBJECTS                    |\n");
	ft_printf("-------------------------------------------------\n");
	while (cpy->next && ++i)
	{
		list_object2(cpy, i);
		if (cpy->next->next)
			ft_printf("-------------------------------------------------\n");
		cpy = cpy->next;
	}
}

int				list_info(char *option, t_rt *rtv1)
{
	if (strcmp(option, "-Com") == 0)
		list_comment(rtv1);
	else if (strcmp(option, "-O") == 0)
		list_object(rtv1);
	else if (strcmp(option, "-All") == 0)
	{
		list_cam(rtv1);
		list_object(rtv1);
		list_comment(rtv1);
	}
	else if (strcmp(option, "-Cam") == 0)
		list_cam(rtv1);
	else
		return (0);
	ft_printf("-------------------------------------------------\n");
	return (1);
}

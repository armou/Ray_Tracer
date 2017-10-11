/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 22:48:33 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 22:06:11 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int			par_bis(char *scene, t_rt *rtv1)
{
	char		*commentary;
	char		*tmp;

	if ((commentary = stock_balise(&scene, "<!--", "-->")) == NULL)
		return (0);
	tmp = rtv1->comment;
	rtv1->comment = ft_strjoin(tmp, commentary);
	free(tmp);
	free(commentary);
	return (1);
}

int			parse_scene(t_rt *rtv1, char *scene)
{
	char		*camera;
	char		*object;
	char		*scene_tmp;

	if ((rtv1->comment = (char *)malloc(sizeof(char) * 1)) == NULL)
		return (0);
	rtv1->comment[0] = '\0';
	while (check_balise(scene, "<!--"))
		if (par_bis(scene, rtv1) == 0)
			return (0);
	if ((scene_tmp = stock_balise(&scene, "<scene>", "</scene>")) == NULL ||
		(camera = stock_balise(&scene_tmp, "<camera>", "</camera>")) == NULL ||
		(object = stock_balise(&scene_tmp, "<object>", "</object>")) == NULL)
		return (0);
	scene = delete_space(scene);
	if (scene[0] != '\0')
		return (f_error("Too much informations in scene : ", scene));
	if (!parse_camera(rtv1, camera) || !parse_object(rtv1, object))
		return (0);
	scene_tmp = delete_space(scene_tmp);
	if (scene_tmp[0] != '\0')
		return (f_error("Too much informations in scene : ", scene_tmp));
	free(scene_tmp);
	free(scene);
	return (1);
}

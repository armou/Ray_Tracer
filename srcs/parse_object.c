/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:37:00 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 21:13:13 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int			parse_object3(t_object *cpy, char *obj_tmp, int i)
{
	if (cpy->type != 7 && cpy->type != 2)
		if ((cpy->size = stock_size(&obj_tmp)) == 0)
			return (0);
	if (cpy->type == 2 && (cpy->size = stock_size_plan(&obj_tmp)) < 0)
		return (f_error("size must be >= to 0 : ", ""));
	if ((cpy->type == 6 || cpy->type == 3 || cpy->type == 4) &&
		(cpy->b_size = stock_b_size(&obj_tmp)) < cpy->size)
		return (f_error("size2 must be more big than size", ""));
	cpy->number = i;
	if (cpy->type == -1)
		return (0);
	return (1);
}

int			parse_object2(t_object *cpy, char *obj_tmp, int i)
{
	char	*tmp;

	tmp = NULL;
	if (parse_object3(cpy, obj_tmp, i) == 0)
		return (0);
	if (stock_origin(&obj_tmp, &cpy->origin) == 0)
		return (f_error("too much or few arguments for origin object", ""));
	if (cpy->type != 5 && stock_rotation(&obj_tmp, &cpy->rot) == 0)
		return (f_error("too much or few arguments for rotation object", ""));
	if (cpy->type == 7 && stock_trois(&obj_tmp, &cpy->trois) == 0)
		return (f_error("too much or few arguments for origin object", ""));
	if ((cpy->reflection = stock_reflection(&obj_tmp)) == -1)
		return (0);
	if ((cpy->texture = stock_texture(&obj_tmp)) < 0)
		return (0);
	tmp = stock_balise(&obj_tmp, "<color>", "</color>");
	if (get_color(&tmp, &cpy->color) < 0)
		return (0);
	obj_tmp = delete_space(obj_tmp);
	if (obj_tmp[0] != '\0')
		return (f_error("Too much arguments for object : ", obj_tmp));
	free(obj_tmp);
	free(tmp);
	return (1);
}

int			cpy_list(t_object **cpy, t_object **current)
{
	if (*cpy == NULL)
	{
		if (!(*cpy = (t_object *)malloc(sizeof(t_object))))
			return (f_error("Malloc object fail : ", ""));
		*current = *cpy;
	}
	else
	{
		if (!((*cpy)->next = (t_object *)malloc(sizeof(t_object))))
			return (f_error("Malloc object fail : ", ""));
		*cpy = (*cpy)->next;
	}
	return (1);
}

int			parse_object(t_rt *rtv1, char *object)
{
	char		*obj_tmp;
	t_object	*cpy;
	t_object	*current;
	int			i;
	int			type;

	i = 1;
	cpy = NULL;
	while ((type = check_obj(&object, &obj_tmp)) != 0)
	{
		if (cpy_list(&cpy, &current) == -1)
			return (0);
		cpy->type = type;
		if (parse_object2(cpy, obj_tmp, i) == 0)
			return (0);
		cpy->next = NULL;
		i++;
	}
	rtv1->object = current;
	object = delete_space(object);
	if (object[0] != '\0')
		return (f_error("Too much arguments for object : ", object));
	free(object);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:28:53 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 20:56:30 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int			check_obj_bis(char **scene, char **tmp)
{
	if (check_balise(*scene, "<cone>"))
	{
		if ((*tmp = stock_balise(scene, "<cone>", "</cone>")) != NULL)
			return (3);
		return (-1);
	}
	if (check_balise(*scene, "<cylindre>"))
	{
		if ((*tmp = stock_balise(scene, "<cylindre>", "</cylindre>")) != NULL)
			return (4);
		return (-1);
	}
	if (check_balise(*scene, "<spot>"))
	{
		if ((*tmp = stock_balise(scene, "<spot>", "</spot>")) != NULL)
			return (5);
		return (-1);
	}
	return (0);
}

int			check_obj(char **scene, char **tmp)
{
	if (check_balise(*scene, "<sphere>"))
	{
		if ((*tmp = stock_balise(scene, "<sphere>", "</sphere>")) != NULL)
			return (1);
		return (-1);
	}
	if (check_balise(*scene, "<plan>"))
	{
		if ((*tmp = stock_balise(scene, "<plan>", "</plan>")) != NULL)
			return (2);
		return (-1);
	}
	if (check_balise(*scene, "<torus>"))
	{
		if ((*tmp = stock_balise(scene, "<torus>", "</torus>")) != NULL)
			return (6);
		return (-1);
	}
	if (check_balise(*scene, "<triangle>"))
	{
		if ((*tmp = stock_balise(scene, "<triangle>", "</triangle>")) != NULL)
			return (7);
		return (-1);
	}
	return (check_obj_bis(scene, tmp));
}

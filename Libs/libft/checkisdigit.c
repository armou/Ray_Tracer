/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkisdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:42:33 by ddufour           #+#    #+#             */
/*   Updated: 2017/04/14 11:12:44 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checkisvalid(char *buff)
{
	int a;

	a = -1;
	while (buff[++a])
		if (buff[a] != '1' && buff[a] != '0' && buff[a] != 'S')
			ft_exit(2, "Use a valid map\n");
}

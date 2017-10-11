/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:46:21 by ddufour           #+#    #+#             */
/*   Updated: 2017/04/14 11:10:19 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(int error, char *message)
{
	if (error == 0)
		exit(write(1, "Program close\n", 14));
	if (error == 1)
	{
		write(2, "Malloc Error in :\n[", 19);
		write(2, message, ft_strlen(message));
		write(2, "]\n", 2);
		exit(-1);
	}
	if (error == 2)
	{
		write(2, message, ft_strlen(message));
		exit(0);
	}
}

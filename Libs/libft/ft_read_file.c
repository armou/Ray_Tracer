/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 12:19:43 by ddufour           #+#    #+#             */
/*   Updated: 2017/02/02 15:49:14 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(char *av)
{
	int		ret;
	int		fd;
	char	*map;
	char	buff[BUFF_SIZE + 1];

	if (!(map = (char*)ft_memalloc(sizeof(char) * 1)))
		return (NULL);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(map = ft_strjoinfree(map, buff)))
			return (NULL);
	}
	if (ret == -1)
		return (NULL);
	close(fd);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 00:12:27 by daugier           #+#    #+#             */
/*   Updated: 2017/08/06 18:10:43 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		more_convert_type(char c, va_list ap)
{
	if (c == 'f')
		ft_putstr(ft_ftoa(va_arg(ap, double)));
}

static void		convert_type(char c, char c2, va_list ap)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int));
	else if (c == 'C' || (c == 'l' && c2 == 'c'))
		ft_putchar(va_arg(ap, int));
	else if (c == 's')
		ft_putstr(va_arg(ap, char *));
	else if (c == 'S' || (c == 'l' && c2 == 's'))
		ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i' || c == 'o' || c == 'u' ||
			(c == 'l' && c2 == 'o') || c == 'O' ||
			c == 'U' || (c == 'l' && c2 == 'u'))
		ft_putnbr(va_arg(ap, int));
	else if (c == 'p')
	{
		ft_putstr("0x");
		ft_putstr((ft_convert_base(ft_itoa(va_arg(ap, int)), DECI, HEXA)));
	}
	else if (c == 'D' || (c == 'l' && c2 == 'd'))
		ft_putnbr(va_arg(ap, int));
	more_convert_type(c, ap);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;

	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			++i;
			convert_type(format[i], format[i + 1], ap);
		}
		else
			ft_putchar(format[i]);
	}
	va_end(ap);
	return (0);
}

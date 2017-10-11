/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gubourge <gubourge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:13:11 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 20:23:40 by gubourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef	struct			s_color
{
	cl_double			r;
	cl_double			g;
	cl_double			b;
	cl_double			a;
}						t_color;

typedef struct			s_camera
{
	t_pos				origin;
	t_pos				dir;
	t_pos				rot;
}						t_camera;

typedef struct			s_object
{
	cl_int				number;
	cl_int				type;
	t_pos				origin;
	t_pos				rot;
	t_pos				trois;
	cl_double			size;
	cl_double			b_size;
	cl_double			reflection;
	t_color				color;
	cl_int				texture;
	struct s_object		*next;
}						t_object;

#endif

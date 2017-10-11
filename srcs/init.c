/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:30:28 by David             #+#    #+#             */
/*   Updated: 2017/10/05 22:33:36 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int		init_param(t_rt *rtv1)
{
	rtv1->alia_tmp = 1;
	rtv1->moove = 0;
	rtv1->offset_x = 0;
	rtv1->offset_y = 0;
	rtv1->screen_tmp = NULL;
	rtv1->run = 1;
	rtv1->aliasing = 1;
	rtv1->tmp_obj = NULL;
	rtv1->xx = 1;
	rtv1->motion_blur = 0;
	rtv1->density = 0;
	rtv1->filter = 0;
	rtv1->ambiante = 0.5;
	return (0);
}

void	creat_perm(t_rt *rtv1)
{
	int		tmp[256];
	int		a;
	int		tmp2;

	a = -1;
	while (++a < 256)
		tmp[a] = 0;
	a = -1;
	while (++a < 256)
	{
		tmp2 = rand() % 256;
		if (tmp[tmp2] == 0)
		{
			rtv1->opencl.permutation[a] = tmp2;
			tmp[tmp2] = 1;
		}
		else
			a--;
	}
}

void	cpy_texture(t_rt *rtv1)
{
	cpy_texture2(rtv1->t1, &rtv1->opencl.size_t1, &rtv1->opencl.w1,\
		&rtv1->opencl.h1);
	cpy_texture2(rtv1->t2, &rtv1->opencl.size_t2, &rtv1->opencl.w2,\
		&rtv1->opencl.h2);
	cpy_texture2(rtv1->t3, &rtv1->opencl.size_t3, &rtv1->opencl.w3,\
		&rtv1->opencl.h3);
	cpy_texture2(rtv1->t4, &rtv1->opencl.size_t4, &rtv1->opencl.w4,\
		&rtv1->opencl.h4);
	cpy_texture2(rtv1->t5, &rtv1->opencl.size_t5, &rtv1->opencl.w5,\
		&rtv1->opencl.h5);
	rtv1->opencl.bpp1 = rtv1->t1->format->BytesPerPixel;
	rtv1->opencl.bpp2 = rtv1->t2->format->BytesPerPixel;
	rtv1->opencl.bpp3 = rtv1->t3->format->BytesPerPixel;
	rtv1->opencl.bpp4 = rtv1->t4->format->BytesPerPixel;
	rtv1->opencl.bpp5 = rtv1->t5->format->BytesPerPixel;
}

int		init_texture(t_rt *rtv1)
{
	rtv1->t1 = IMG_Load("./img/large_daugier.jpg");
	rtv1->t2 = IMG_Load("./img/large_ddufour.jpg");
	rtv1->t3 = IMG_Load("./img/large_gubourge.jpg");
	rtv1->t4 = IMG_Load("./img/large_aoudin.jpg");
	rtv1->t5 = IMG_Load("./img/eye_texture.jpg");
	rtv1->opencl.data1 = rtv1->t1->pixels;
	rtv1->opencl.data2 = rtv1->t2->pixels;
	rtv1->opencl.data3 = rtv1->t3->pixels;
	rtv1->opencl.data4 = rtv1->t4->pixels;
	rtv1->opencl.data5 = rtv1->t5->pixels;
	cpy_texture(rtv1);
	creat_perm(rtv1);
	return (0);
}

int		init_opencl(t_rt *rt)
{
	int			fp;
	char		*file_buffer;
	size_t		source_size;
	cl_int		error_code;

	fp = open("srcs/rtv.cl", O_RDONLY);
	if (fp == -1)
	{
		ft_putstr("Failed to load rtv.cl\n");
		return (-1);
	}
	if (!(file_buffer = (char *)malloc(MAX_SOURCE_SIZE)))
		return (-1);
	source_size = read(fp, file_buffer, MAX_SOURCE_SIZE);
	close(fp);
	if ((error_code = cl_create_platform(&rt->cl)) != CL_SUCCESS)
		return (cl_erreur_log(&rt->cl, error_code));
	if ((error_code = cl_create_program(&rt->cl, file_buffer, source_size))\
		!= CL_SUCCESS)
		return (cl_erreur_log(&rt->cl, error_code));
	free(file_buffer);
	return (0);
}

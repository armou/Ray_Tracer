/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_cl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:07:59 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 20:57:06 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int		cl_create_buffer(t_rt *rtv1, t_cl_buffer *cl_b)
{
	cl_int	error[7];
	int		i;

	cl_b->data = clCreateBuffer(rtv1->cl.context, 0, sizeof(cl_uchar)
				* (HEIGHT * (WIDTH + 400) * rtv1->opencl.bpp),
				NULL, &error[0]);
	cl_b->opencl = clCreateBuffer(rtv1->cl.context, CL_MEM_READ_ONLY,
				sizeof(rtv1->opencl), NULL, &error[1]);
	cl_b->object = clCreateBuffer(rtv1->cl.context, CL_MEM_READ_ONLY,
				sizeof(t_object) * 300, NULL, &error[2]);
	cl_b->nb_object = clCreateBuffer(rtv1->cl.context, CL_MEM_READ_ONLY,
				sizeof(rtv1->nb_object), NULL, &error[3]);
	cl_b->camera = clCreateBuffer(rtv1->cl.context, CL_MEM_READ_ONLY,
				sizeof(rtv1->camera), NULL, &error[4]);
	cl_b->work_group = clCreateBuffer(rtv1->cl.context, CL_MEM_READ_ONLY,
				sizeof(int), NULL, &error[5]);
	cl_b->work_group2 = clCreateBuffer(rtv1->cl.context, CL_MEM_READ_ONLY,
				sizeof(int), NULL, &error[6]);
	i = -1;
	while (++i < 7)
		if (error[i] != CL_SUCCESS)
			return (error[i]);
	return (0);
}

int		cl_create_kernel_bis(t_kernel *kernel, t_cl_buffer *cl_b)
{
	cl_int	error;

	if ((error = clSetKernelArg(kernel->kernel, 2,
			sizeof(cl_b->object),
			(void *)&cl_b->object)) != CL_SUCCESS)
		return (error);
	if ((error = clSetKernelArg(kernel->kernel, 3,
			sizeof(cl_b->nb_object),
			&cl_b->nb_object)) != CL_SUCCESS)
		return (error);
	if ((error = clSetKernelArg(kernel->kernel, 4,
			sizeof(cl_b->camera),
			&cl_b->camera)) != CL_SUCCESS)
		return (error);
	if ((error = clSetKernelArg(kernel->kernel, 5,
			sizeof(cl_b->work_group),
			&cl_b->work_group)) != CL_SUCCESS)
		return (error);
	if ((error = clSetKernelArg(kernel->kernel, 6,
			sizeof(cl_b->work_group2),
			&cl_b->work_group2)) != CL_SUCCESS)
		return (error);
	return (CL_SUCCESS);
}

int		cl_create_kernel(t_rt *rtv1, t_kernel *kernel, t_cl_buffer *cl_b)
{
	cl_int		error;

	kernel->kernel = clCreateKernel(rtv1->cl.program, "draw_rt", &error);
	if (error != CL_SUCCESS)
		return (error);
	if ((error = cl_create_buffer(rtv1, cl_b)) != CL_SUCCESS)
		return (error);
	if ((error = clSetKernelArg(kernel->kernel, 0,
						sizeof(cl_b->data), &cl_b->data)) != CL_SUCCESS)
		return (error);
	if ((error = clSetKernelArg(kernel->kernel, 1,
						sizeof(cl_b->opencl), &cl_b->opencl)) != CL_SUCCESS)
		return (error);
	if ((error = cl_create_kernel_bis(kernel, cl_b)) != CL_SUCCESS)
		return (error);
	return (0);
}

int		cl_read_buffer_bis(t_rt *rtv1, t_cl_buffer *cl_b)
{
	cl_int	error;

	if ((error = clEnqueueWriteBuffer(rtv1->cl.command_queue, cl_b->data,
						CL_TRUE, 0, sizeof(cl_uchar) * (HEIGHT * (WIDTH + 400) *
						rtv1->opencl.bpp), rtv1->screen->pixels,
						0, NULL, NULL)) != CL_SUCCESS)
		return (error);
	if ((error = clEnqueueWriteBuffer(rtv1->cl.command_queue, cl_b->opencl,
						CL_TRUE, 0, sizeof(rtv1->opencl), (void *)&rtv1->opencl,
						0, NULL, NULL)) != CL_SUCCESS)
		return (error);
	if ((error = clEnqueueWriteBuffer(rtv1->cl.command_queue, cl_b->object,
						CL_TRUE, 0, sizeof(t_object) * rtv1->nb_object,
						rtv1->tab_object, 0, NULL, NULL)) != CL_SUCCESS)
		return (error);
	if ((error = clEnqueueWriteBuffer(rtv1->cl.command_queue, cl_b->nb_object,
						CL_TRUE, 0, sizeof(rtv1->nb_object),
						(void *)&rtv1->nb_object, 0, NULL, NULL)) != CL_SUCCESS)
		return (error);
	if ((error = clEnqueueWriteBuffer(rtv1->cl.command_queue, cl_b->camera,
						CL_TRUE, 0, sizeof(rtv1->camera), (void *)&rtv1->camera,
						0, NULL, NULL)) != CL_SUCCESS)
		return (error);
	return (CL_SUCCESS);
}

int		cl_read_buffer(t_rt *rtv1, t_kernel *kernel,
				t_cl_buffer *cl_b, size_t *giz)
{
	cl_int		error;

	if ((error = cl_read_buffer_bis(rtv1, cl_b) != CL_SUCCESS))
		return (error);
	if ((error = clEnqueueWriteBuffer(rtv1->cl.command_queue, cl_b->work_group,
						CL_TRUE, 0,
						sizeof(rtv1->offset_x), (void *)&rtv1->offset_x,
						0, NULL, NULL)) != CL_SUCCESS)
		return (error);
	if ((error = clEnqueueWriteBuffer(rtv1->cl.command_queue, cl_b->work_group2,
						CL_TRUE, 0, sizeof(rtv1->offset_y),
						(void *)&rtv1->offset_y, 0, NULL, NULL)) != CL_SUCCESS)
		return (error);
	if ((error = clEnqueueNDRangeKernel(rtv1->cl.command_queue, kernel->kernel,
						2, NULL, giz, NULL, 0, NULL, NULL))
						!= CL_SUCCESS)
		return (error);
	clFinish(rtv1->cl.command_queue);
	if ((error = clEnqueueReadBuffer(rtv1->cl.command_queue, cl_b->data,
						CL_TRUE, 0, sizeof(cl_uchar) *
						(HEIGHT * (WIDTH + 400) * rtv1->opencl.bpp),
						rtv1->screen->pixels, 0, NULL,
						NULL)) != CL_SUCCESS)
		return (error);
	return (CL_SUCCESS);
}

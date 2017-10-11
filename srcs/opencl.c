/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:59:19 by gubourge          #+#    #+#             */
/*   Updated: 2017/10/05 20:56:40 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int			cl_erreur_log(t_cl *cl, cl_int error)
{
	char	*log;
	size_t	length_log;

	ft_putnbr(error);
	ft_putchar('\n');
	clGetProgramBuildInfo(cl->program, cl->device, CL_PROGRAM_BUILD_LOG,
			0, NULL, &length_log);
	log = (char *)malloc(length_log);
	clGetProgramBuildInfo(cl->program, cl->device,
			CL_PROGRAM_BUILD_LOG, length_log, log, NULL);
	ft_putstr("\n[IMPRESSION DU JOURNAL DE COMPILATION]\n\n");
	ft_putstr(log);
	ft_putstr("\n\n");
	ft_putstr("[FIN DU JOURNAL]\n\n");
	free(log);
	return (-1);
}

int			cl_create_platform(t_cl *cl)
{
	cl_int					error;
	cl_device_fp_config		fp;

	if ((error = clGetPlatformIDs(1, &cl->platform, NULL)) != CL_SUCCESS)
		return (error);
	if ((error = clGetDeviceIDs(cl->platform, CL_DEVICE_TYPE_CPU, 1,
					&cl->device, &cl->num_entries)) != CL_SUCCESS)
		return (error);
	if ((error = clGetDeviceInfo(cl->device, CL_DEVICE_DOUBLE_FP_CONFIG,
					sizeof(cl_device_fp_config), &fp, NULL))
			!= CL_SUCCESS)
		return (error);
	cl->properties[0] = (cl_context_properties)CL_CONTEXT_PLATFORM;
	cl->properties[1] = (cl_context_properties)cl->platform;
	cl->properties[2] = 0;
	cl->context = clCreateContext(cl->properties, 1,
			&cl->device, NULL, NULL, &error);
	if (error != CL_SUCCESS)
		return (error);
	return (0);
}

int			cl_create_program(t_cl *cl, const char *file_buffer,
				size_t source_size)
{
	cl_int	error;

	cl->command_queue = clCreateCommandQueue(cl->context, cl->device,
			CL_QUEUE_PROFILING_ENABLE,
			&error);
	if (error != CL_SUCCESS)
		return (error);
	cl->program = clCreateProgramWithSource(cl->context, 1,
			(const char **)&file_buffer,
			(const size_t *)&source_size,
			&error);
	if (error != CL_SUCCESS)
		return (error);
	error = clBuildProgram(cl->program, 1,
			&cl->device,
			"-cl-fast-relaxed-math",
			NULL,
			NULL);
	if (error != CL_SUCCESS)
		return (error);
	return (0);
}

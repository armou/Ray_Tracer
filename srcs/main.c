/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 11:14:58 by ddufour           #+#    #+#             */
/*   Updated: 2017/10/16 19:36:03 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

int		init_rt(t_rt *rtv1)
{
	init_texture(rtv1);
	init_param(rtv1);
	SDL_Init(SDL_INIT_VIDEO);
	if (!(rtv1->window = SDL_CreateWindow("RT FRAGILE", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN))) // add + 400 to width to see interface
		return (-1);
	rtv1->screen = SDL_GetWindowSurface(rtv1->window);
	// interface(rtv1);
	rtv1->opencl.sizeline = rtv1->screen->pitch;
	rtv1->opencl.bpp = rtv1->screen->format->BytesPerPixel;
	if ((cl_create_kernel(rtv1, &rtv1->kernel, &rtv1->cl_b)) != CL_SUCCESS)
	{
		ft_printf("Kernel Error \n");
		return (-1);
	}
	rtv1->tab_object = NULL;
	return (0);
}

void	move_draw(t_rt *rtv1)
{
	ft_moove(rtv1);
	if (!rtv1->motion_blur)
	{
		rtv1->offset_x = 0;
		rtv1->offset_y = 0;
	}
}

void	classic_draw(t_rt *rtv1)
{
	if (draw_rt(rtv1) == -1)
		exit(0);
	++rtv1->offset_x;
	if (rtv1->offset_x == 10 && rtv1->offset_y < 10)
	{
		++rtv1->offset_y;
		rtv1->offset_x = 0;
	}
}

int		rtv1(t_rt *rtv1)
{
	if (init_rt(rtv1) == -1)
		return (-1);
	while (rtv1->run == 1)
	{
		if (SDL_PollEvent(&rtv1->event))
			event_rt(rtv1);
		if (MOOVE)
			move_draw(rtv1);
		if (rtv1->offset_x < 10 && rtv1->offset_y < 10)
			classic_draw(rtv1);
		if (rtv1->offset_y == 10 && rtv1->motion_blur)
		{
			rtv1->offset_x = 0;
			rtv1->offset_y = 0;
		}
	}
	SDL_DestroyWindow(rtv1->window);
	SDL_Quit();
	return (0);
}

int		main(int ac, char **av)
{
	t_rt		rt;

	if (ac == 3 || ac == 2)
	{
		if (!stock_object(av[1], &rt))
			return (0);
	}
	if (ac == 2)
	{
		if (init_opencl(&rt) == -1)
			return (0);
		rtv1(&rt);
	}
	else if (ac == 3)
	{
		if (list_info(av[2], &rt) == 0)
			return (write(1, "invalid option\n", 15));
	}
	else if (ac < 2)
		ft_printf("no map done\n");
	else
		ft_printf("too much map done\n");
	return (0);
}

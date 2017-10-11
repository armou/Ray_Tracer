/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <daugier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 18:50:05 by David             #+#    #+#             */
/*   Updated: 2017/10/05 20:56:12 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/rt.h"

void	print_font(t_rt *rtv1, int posx, int posy, char *wrt)
{
	SDL_Surface		*writing;
	SDL_Color		color;
	TTF_Font		*font;

	TTF_Init();
	font = TTF_OpenFont(FONT, (posy == 0) ? 34 : 18);
	color = (SDL_Color){247, 119, 93, 0};
	writing = TTF_RenderText_Solid(font, wrt, color);
	SDL_BlitSurface(writing, NULL, rtv1->screen, \
			&((SDL_Rect){WIDTH + posx, posy, 0, 0}));
	TTF_CloseFont(font);
	SDL_FreeSurface(writing);
	TTF_Quit();
}

void	interface2(t_rt *rtv1)
{
	print_font(rtv1, 15, 610, "Add Torus                : u");
	print_font(rtv1, 15, 640, "Add Plan                  : y");
	print_font(rtv1, 15, 670, "Add Light                 : t");
	print_font(rtv1, 15, 700, "Add Triangle             : r");
}

void	interface(t_rt *rtv1)
{
	print_font(rtv1, 130, 0, "Interface");
	print_font(rtv1, 15, 70,\
			"Origin x                     : fleche gauche / droite");
	print_font(rtv1, 15, 100,\
			"Origin y                    : page-up / page-down");
	print_font(rtv1, 15, 130,\
			"Origin z                     : fleche haut / bas");
	print_font(rtv1, 15, 160, "Rotation x                 : a / d");
	print_font(rtv1, 15, 190, "Rotation y                 : w / s");
	print_font(rtv1, 15, 215, "Size                          : + / -");
	print_font(rtv1, 15, 250, "Modif Normal            : n");
	print_font(rtv1, 15, 280, "Filtre                        : q");
	print_font(rtv1, 15, 310, "Motion Blur               : m");
	print_font(rtv1, 15, 340, "ScreenShot               : o");
	print_font(rtv1, 15, 370, "Modif Color(r/g/b)      : x / c / v");
	print_font(rtv1, 15, 400, "Suprimer Object        : delete");
	print_font(rtv1, 15, 430, "Changer de scene     : 1 / 2 / 3 / 4 / 5");
	print_font(rtv1, 15, 460,\
			"Antialiasing               : l (down) / k (up)");
	print_font(rtv1, 15, 490,\
			"(De)Selection d'objet : clic droit / clic gauche");
	print_font(rtv1, 15, 520, "Affichage obj pos      : z");
	print_font(rtv1, 15, 550, "Centrage Camera     : tab");
	print_font(rtv1, 15, 580, "Add Sphere              : i");
	interface2(rtv1);
}

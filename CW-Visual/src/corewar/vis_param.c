/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ophuong <ophuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:03:34 by ophuong           #+#    #+#             */
/*   Updated: 2021/02/04 20:06:40 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	d_ctd_name(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										"Cycles", cw->vis->clr);
	rect.x = 1250;
	rect.y = 67 * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, cw->vis->scrn, &rect);
		SDL_FreeSurface(text_surface);
	}
}

void	d_ctd_par(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;
	char		*str;

	str = ft_itoa(cw->cycles);
	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										str, cw->vis->clr);
	rect.x = 1250 + 200;
	rect.y = 67 * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, cw->vis->scrn, &rect);
		SDL_FreeSurface(text_surface);
	}
	else
	{
		ft_printf("Draw error!!!");
	}
	free(str);
}

void	d_nkors_name(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										"Quantity of karetka", cw->vis->clr);
	rect.x = 1250;
	rect.y = 69 * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, cw->vis->scrn, &rect);
		SDL_FreeSurface(text_surface);
	}
}

void	d_nkors_par(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;
	char		*str;

	str = ft_itoa(cw->num_of_koretko);
	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										str, cw->vis->clr);
	rect.x = 1250 + 200;
	rect.y = 69 * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, cw->vis->scrn, &rect);
		SDL_FreeSurface(text_surface);
	}
	else
	{
		ft_printf("Draw error!!!");
	}
	free(str);
}

void	draw_param(t_cw *cw)
{
	d_ctd_name(cw);
	d_ctd_par(cw);
	d_nkors_name(cw);
	d_nkors_par(cw);
	d_lp_name(cw);
	d_lp_par(cw);
	d_p1n_name(cw);
	d_p1n_par(cw);
	d_p1l_name(cw);
	d_p1l_par(cw);
	d_p2n_name(cw);
	d_p2n_par(cw);
	d_p2l_name(cw);
	d_p2l_par(cw);
}

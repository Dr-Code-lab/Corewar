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

void	d_p1n_name(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										"Player 1", cw->vis->clr);
	rect.x = 25;
	rect.y = 67 * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, cw->vis->scrn, &rect);
		SDL_FreeSurface(text_surface);
	}
}

void	d_p1n_par(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										cw->champs[0]->name, cw->vis->clr);
	rect.x = 25 + 200;
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
}

void	d_p1l_name(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										"Comment:", cw->vis->clr);
	rect.x = 25;
	rect.y = 69 * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, cw->vis->scrn, &rect);
		SDL_FreeSurface(text_surface);
	}
}

void	d_p1l_par(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										cw->champs[0]->comm, cw->vis->clr);
	rect.x = 25 + 200;
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
}

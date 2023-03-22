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

void	d_p2n_name(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										"Player 2", cw->vis->clr);
	rect.x = 25;
	rect.y = 72 * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, cw->vis->scrn, &rect);
		SDL_FreeSurface(text_surface);
	}
}

void	d_p2n_par(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										cw->champs[1]->name, cw->vis->clr);
	rect.x = 25 + 200;
	rect.y = 72 * 14;
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

void	d_p2l_name(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										"Comment:", cw->vis->clr);
	rect.x = 25;
	rect.y = 74 * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, cw->vis->scrn, &rect);
		SDL_FreeSurface(text_surface);
	}
}

void	d_p2l_par(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										cw->champs[1]->comm, cw->vis->clr);
	rect.x = 25 + 200;
	rect.y = 74 * 14;
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

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

void	get_clr_param(t_cw *cw)
{
	cw->vis->clr.r = 255;
	cw->vis->clr.g = 255;
	cw->vis->clr.b = 255;
	cw->vis->clr.a = 255;
}

void	d_lp_name(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										"Last player", cw->vis->clr);
	rect.x = 1250;
	rect.y = 72 * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, cw->vis->scrn, &rect);
		SDL_FreeSurface(text_surface);
	}
}

void	d_lp_par(t_cw *cw)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;
	char		*str;

	str = ft_itoa(cw->last_player * -1);
	get_clr_param(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
										str, cw->vis->clr);
	rect.x = 1250 + 200;
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
	free(str);
}

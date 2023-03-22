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

void	vis_init(t_cw *cw)
{
	cw->vis = malloc(sizeof(t_vis));
	if (!(cw->vis->font_path = "100.ttf"))
	{
		fprintf(stderr, "error: too many arguments\n");
		exit(EXIT_FAILURE);
	}
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	cw->vis->font = TTF_OpenFont(cw->vis->font_path, 12);
	if (cw->vis->font == NULL)
	{
		fprintf(stderr, "error: font not found\n");
		exit(EXIT_FAILURE);
	}
	cw->vis->wind = SDL_CreateWindow("COREWAR",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	cw->vis->scrn = SDL_GetWindowSurface(cw->vis->wind);
	cw->vis->sur = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
	cw->vis->quit = 0;
}

int		draw_text(SDL_Surface *screen, t_cw *cw, int pos, int x)
{
	SDL_Surface	*text_surface;
	SDL_Rect	rect;

	get_clr(cw);
	text_surface = TTF_RenderText_Solid(cw->vis->font,
		cw->vis->line, cw->vis->clr);
	rect.x = 25 + x;
	rect.y = pos * 14;
	if (text_surface != NULL)
	{
		SDL_BlitSurface(text_surface, NULL, screen, &rect);
		SDL_FreeSurface(text_surface);
		return (1);
	}
	else
	{
		ft_printf("Draw error!!!");
		return (0);
	}
}

void	read_and_draw(t_cw *cw)
{
	size_t	o;
	size_t	tmp;
	int		y;
	int		x;

	y = 2;
	x = 0;
	o = 0;
	cw->vis->b_n = 0;
	while (o < MEM_SIZE)
	{
		tmp = 0;
		while (tmp < 64 && o < MEM_SIZE)
		{
			ft_print_hex_to_line(cw->map[o], cw);
			draw_text(cw->vis->scrn, cw, y, x);
			cw->vis->b_n++;
			o++;
			x += 25;
			tmp++;
		}
		y++;
		x = 0;
	}
	draw_param(cw);
}

void	visualiser(t_cw *cw)
{
	read_and_draw(cw);
	ft_memcpy(cw->vis->map_cpy, (const char *)cw->map, MEM_SIZE);
	SDL_UpdateWindowSurface(cw->vis->wind);
	SDL_BlitSurface(cw->vis->sur, NULL, cw->vis->scrn, NULL);
	SDL_Delay(2);
}

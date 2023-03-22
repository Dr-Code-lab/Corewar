/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ophuong <ophuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:03:34 by ophuong           #+#    #+#             */
/*   Updated: 2021/02/04 20:06:40 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	set_clr(t_cw *cw, int r, int g, int b)
{
	cw->vis->clr.r = r;
	cw->vis->clr.g = g;
	cw->vis->clr.b = b;
	cw->vis->clr.a = 255;
	if (r == 207 && g == 55 && b == 91)
		cw->vis->n_col[cw->vis->b_n] = 1;
	else if (r == 229 && g == 179 && b == 76)
		cw->vis->n_col[cw->vis->b_n] = 2;
	else if (r == 89 && g == 178 && b == 129)
		cw->vis->n_col[cw->vis->b_n] = 3;
	else if (r == 97 && g == 194 && b == 235)
		cw->vis->n_col[cw->vis->b_n] = 4;
	else
		cw->vis->n_col[cw->vis->b_n] = 0;
}

void	get_clr_for_2(t_cw *cw)
{
	if (cw->vis->b_n < 2048 &&
		cw->vis->b_n <= cw->champs[0]->code_size)
		set_clr(cw, RED);
	else if (cw->vis->b_n > 2048 &&
			cw->vis->b_n <= 2048 + cw->champs[1]->code_size)
		set_clr(cw, YELLOW);
	else if (cw->vis->map_cpy[cw->vis->b_n] == cw->map[cw->vis->b_n] &&
			cw->vis->n_col[cw->vis->b_n] == 1)
		set_clr(cw, RED);
	else if (cw->vis->map_cpy[cw->vis->b_n] == cw->map[cw->vis->b_n] &&
			cw->vis->n_col[cw->vis->b_n] == 2)
		set_clr(cw, YELLOW);
	else if (cw->vis->par_id == 1 &&
			cw->vis->map_cpy[cw->vis->b_n] != cw->map[cw->vis->b_n])
		set_clr(cw, RED);
	else if (cw->vis->par_id == 2 &&
			cw->vis->map_cpy[cw->vis->b_n] != cw->map[cw->vis->b_n])
		set_clr(cw, YELLOW);
	else
		set_clr(cw, GREY);
}

void	get_clr_for_3(t_cw *cw)
{
	if ((cw->vis->map_cpy[cw->vis->b_n] != cw->map[cw->vis->b_n] &&
		cw->vis->par_id == 1) || (cw->vis->b_n < 1365 &&
		cw->vis->b_n <= cw->champs[0]->code_size))
		set_clr(cw, RED);
	else if ((cw->vis->map_cpy[cw->vis->b_n] != cw->map[cw->vis->b_n] &&
		cw->vis->par_id == 2) || (cw->vis->b_n > 1365 &&
		cw->vis->b_n < 2730 && cw->vis->b_n <= 1365 + cw->champs[1]->code_size))
		set_clr(cw, GREEN);
	else if ((cw->vis->map_cpy[cw->vis->b_n] != cw->map[cw->vis->b_n] &&
		cw->vis->par_id == 3) || (cw->vis->b_n > 2730 &&
		cw->vis->b_n <= 2730 + cw->champs[2]->code_size))
		set_clr(cw, YELLOW);
	else
		set_clr(cw, GREY);
}

void	get_clr_for_4(t_cw *cw)
{
	if ((cw->vis->map_cpy[cw->vis->b_n] != cw->map[cw->vis->b_n] &&
		cw->vis->par_id == 1) || (cw->vis->b_n < 1024 &&
		cw->vis->b_n <= cw->champs[0]->code_size))
		set_clr(cw, RED);
	else if ((cw->vis->map_cpy[cw->vis->b_n] != cw->map[cw->vis->b_n] &&
		cw->vis->par_id == 2) || (cw->vis->b_n > 1024 && cw->vis->b_n < 2048 &&
		cw->vis->b_n <= 1024 + cw->champs[1]->code_size))
		set_clr(cw, GREEN);
	else if ((cw->vis->map_cpy[cw->vis->b_n] != cw->map[cw->vis->b_n] &&
		cw->vis->par_id == 3) || (cw->vis->b_n > 2048 && cw->vis->b_n < 3072 &&
		cw->vis->b_n <= 2048 + cw->champs[2]->code_size))
		set_clr(cw, YELLOW);
	else if ((cw->vis->map_cpy[cw->vis->b_n] != cw->map[cw->vis->b_n] &&
		cw->vis->par_id == 4) || (cw->vis->b_n > 3072 &&
		cw->vis->b_n <= 3072 + cw->champs[3]->code_size))
		set_clr(cw, BLUE);
	else
		set_clr(cw, GREY);
}

void	get_clr(t_cw *cw)
{
	if (cw->num_of_champ == 1)
	{
		ft_printf("Please give me more champs!\n");
		exit(0);
	}
	if (cw->num_of_champ == 2)
		get_clr_for_2(cw);
	if (cw->num_of_champ == 3)
		get_clr_for_3(cw);
	if (cw->num_of_champ == 4)
		get_clr_for_4(cw);
}

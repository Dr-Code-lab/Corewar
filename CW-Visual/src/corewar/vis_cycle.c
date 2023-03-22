/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_cycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ophuong <ophuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:03:34 by ophuong           #+#    #+#             */
/*   Updated: 2021/02/04 20:06:40 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	main_loop(t_cw *cw)
{
	while (cw->num_of_koretko && (!cw->vis->quit))
	{
		while (SDL_PollEvent(&cw->vis->eve) != 0)
		{
			if (cw->vis->eve.type == SDL_QUIT)
				cw->vis->quit = 1;
			else if (cw->vis->eve.type == SDL_KEYDOWN)
				cw->vis->quit = 1;
		}
		if (cw->dump_cycle == cw->cycles)
		{
			ft_print_memory(cw->map, 4096);
			exit(1);
		}
		make_op(cw);
		if (cw->cycles_to_die == cw->cycles_to_check
			|| cw->cycles_to_die <= 0)
		{
			check_cycles(cw);
			cycle_to_die_check(cw);
		}
	}
}

void	make_cycle(t_cw *cw)
{
	vis_init(cw);
	ft_memcpy(cw->vis->map_cpy, (const char *)cw->map, MEM_SIZE);
	visualiser(cw);
	main_loop(cw);
	cw->last_player *= -1;
	ft_printf("Contestant %d, \"%s\", has won !\n",
		cw->last_player, cw->champs[cw->last_player - 1]->name);
	vis_deinit(cw);
	free(cw->vis);
	free_after_finish(cw);
}

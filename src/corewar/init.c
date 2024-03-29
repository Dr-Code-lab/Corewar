/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:37:21 by hlikely           #+#    #+#             */
/*   Updated: 2021/02/04 19:38:02 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	introducing(t_cw *cw)
{
	int i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < cw->num_of_champ)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
					cw->champs[i]->number, cw->champs[i]->code_size,
					cw->champs[i]->name, cw->champs[i]->comm);
}

void	place_pl_and_kors(t_cw *cw)
{
	int			position;
	int			player_id;
	t_koretko	*kor;

	position = 0;
	player_id = 0;
	cw->last_player = cw->champs[cw->num_of_champ - 1]->number * -1;
	cw->cycles_to_die = CYCLE_TO_DIE;
	while (++player_id <= cw->num_of_champ)
	{
		ft_memcpy(&(cw->map[position]), cw->champs[player_id - 1]->code,
						(size_t)cw->champs[player_id - 1]->code_size);
		cw->last_id++;
		kor = create_koretko(cw->last_id, position);
		kor->regs[0] = player_id * -1;
		kor->parent_id = player_id;
		if (cw->num_of_koretko > 0)
			chain_kor(&cw->kors, kor);
		else
			cw->kors = kor;
		position += MEM_SIZE / cw->num_of_champ;
		cw->num_of_koretko++;
	}
	introducing(cw);
}

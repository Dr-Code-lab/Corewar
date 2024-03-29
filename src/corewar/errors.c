/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:01:35 by hlikely           #+#    #+#             */
/*   Updated: 2021/02/13 22:38:35 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

void	output_error(int n, t_cw *cw)
{
	n == 1 ? write(2, "Wrong MAGIC number\n", 19) : 0;
	n == 2 ? write(2, "Wrong file name\n", 19) : 0;
	n == 3 ? write(2, "No NULL in .cor file\n", 22) : 0;
	n == 4 ? write(2, "Wrong champ size\n", 18) : 0;
	n == 5 ? write(2, "Wrong quantity of players\n", 27) : 0;
	n == 6 ? write(2, "Wrong value after flag -n\n", 27) : 0;
	n == 7 ? write(2, "Need a value after argument\n", 29) : 0;
	n == 8 ? write(2, "Wrong value after flag -d\n", 27) : 0;
	n == 9 ? write(2, "Can't open file\n", 17) : 0;
	n == 10 ? write(2, "Size of champion is too small\n", 31) : 0;
	n == 11 ? write(2, "Too many players\n", 18) : 0;
	free_after_finish(cw);
	exit(1);
}

void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-d N -n N -v] <champion.cor> <...>\n\n"
			" -d / -dump N      : Dumps memory after N cycles then exits\n"
			" -n N              : Set order number for player\n"
			" -v                : SDL visualization\n");
	exit(1);
}

void	free_after_finish(t_cw *cw)
{
	int	i;

	i = -1;
	if (cw->num_of_champ != 0)
	{
		while (++i < cw->num_of_champ && cw->champs[i] != NULL)
		{
			free(cw->champs[i]->name);
			free(cw->champs[i]->comm);
			free(cw->champs[i]->code);
			free(cw->champs[i]);
		}
	}
	free(cw);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:05:18 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/11 19:33:52 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void				zap_label(t_new_st_label **label, t_op_strukt *op)
{
	t_label			*lab;
	t_new_st_label	*new_label;

	new_label = *label;
	while (new_label->next)
		new_label = new_label->next;
	lab = new_label->lab;
	while (lab)
	{
		lab->op = op;
		lab = lab->next;
	}
}

int					prob(char *line)
{
	int k;
	int	probel;

	probel = number_pr(line);
	if (((k = kol_sim(line, '%')) != -1) && ((probel != -3 && k < probel) \
				|| (probel == -3)))
		probel = kol_sim(line, '%');
	if (((k = kol_sim(line, '-')) != -1) && ((probel != -3 && k < probel) \
				|| (probel == -3)))
		probel = kol_sim(line, '-');
	return (probel);
}

void				smechenee(t_chempion *ch, t_op_strukt *new_op, \
t_new_st_label **label)
{
	t_new_st_label	*new_label;

	new_op->smechenee = ch->smehenee;
	ch->smehenee += new_op->size;
	if (ch->flag_label == 1)
	{
		new_label = label_last(label);
		new_label->smehenee = ch->smehenee;
	}
}

int					pars_operation2(int probel, char *li, t_op_strukt *new_op)
{
	char			*srez2;
	int				n;

	srez2 = ft_strdup(&li[probel]);
	probel = prop_probel(srez2);
	n = 0;
	if ((pars_register(&srez2[probel], &new_op, n)) < 0)
	{
		free(srez2);
		return (-1);
	}
	free(srez2);
	return (1);
}

int					pars_operation(char *line, t_chempion *ch, \
		t_op_strukt **op, t_new_st_label **label)
{
	char			*srez;
	t_op_strukt		*new_op;
	int				probel;

	if ((probel = prob(line)) == -3)
		probel = 0;
	srez = cut_one(&line[prop_probel(line)], \
	line[prop_probel(line) + probel], 0);
	if (operation_name(srez, op) < 0)
	{
		free(srez);
		return (-1);
	}
	free(srez);
	if (ch->flag_label == 1)
		zap_label(label, operation_last(op));
	new_op = operation_last(op);
	if (line[prop_probel(line) + probel] == DIRECT_CHAR)
		probel = prop_probel(line) + probel;
	if (pars_operation2(probel, line, new_op) < 0)
		return (-1);
	smechenee(ch, new_op, label);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proverca_registra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:28:45 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/11 21:32:37 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int					proverca_instruction2(char *str2, t_chempion *ch, \
t_label *lab)
{
	if (lab->op == NULL)
	{
		free(str2);
		return (ch->smehenee - ch->mestnoe_smehenee);
	}
	free(str2);
	return (lab->op->smechenee - ch->mestnoe_smehenee);
}

int					proverca_instruction(char *str, t_chempion *ch, \
t_new_st_label *label)
{
	t_new_st_label	*label2;
	t_label			*lab;
	char			*str2;
	int				i;

	str2 = ft_strdup(str);
	i = number_pr(str2);
	if (i != -3 && i < (int)ft_strlen(str))
		str2[i] = '\0';
	label2 = label;
	while (label2)
	{
		lab = label2->lab;
		while (lab)
		{
			if ((ft_strcmp(lab->name, str2)) == 0)
				return (proverca_instruction2(str2, ch, lab));
			lab = lab->next;
		}
		label2 = label2->next;
	}
	ch->flag = -1;
	free(str2);
	return (-1);
}

void				byte_code(short tmp2, t_chempion *ch)
{
	ch->code[ch->tu] = tmp2 >> 8;
	(ch->tu)++;
	ch->code[ch->tu] = tmp2 & 255;
}

int					proverca_registr_add(char *srez, t_chempion *ch, \
		t_new_st_label *label, t_op_strukt *new_op)
{
	if (srez[1] == LABEL_CHAR)
	{
		if (label_last(&label)->lab->op == NULL)
			label->lab->op->smechenee = 0;
		if (proverca_registr2(srez, ch, label, new_op) < 0)
			return (-1);
	}
	else if (proverca_registr3(srez, ch, new_op) < 0)
		return (-1);
	return (0);
}

int					proverca_registr(char *srez, t_chempion *ch, \
		t_new_st_label *label, t_op_strukt *new_op)
{
	long			tmp;

	if (srez[0] == 'r')
	{
		if ((tmp = ft_atoi(&srez[1])) <= 99 && tmp >= 0)
			ch->code[ch->tu] = tmp;
		else
			return (-1);
	}
	else if (srez[0] == DIRECT_CHAR)
	{
		if (proverca_registr_add(srez, ch, label, new_op) == -1)
			return (-1);
	}
	else if (srez[0] == LABEL_CHAR)
	{
		if (proverca_registr2(srez, ch, label, new_op) < 0)
			return (-1);
	}
	else if ((tmp = ft_latoi(srez)) >= 0)
		byte_code(tmp, ch);
	else if ((tmp = ft_latoi(srez)) < 0)
		byte_code(4294967296 + tmp, ch);
	return (1);
}

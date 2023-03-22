/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:49:26 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/13 18:55:18 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char				op_reg2(unsigned char type, int kol)
{
	type = type << 2;
	if (kol == 1)
		type = type << 4;
	else if (kol == 2)
		type = type << 2;
	return (type);
}

char				*op_reg3(int n, char **str, int *tecyhee, \
		unsigned char *type)
{
	char			*srez;
	int				k;

	if (n >= 0)
	{
		srez = cut_one(&((*str)[*tecyhee]), SEPARATOR_CHAR, 0);
		(*tecyhee) += n + 1;
		(*str) = (*str) + *tecyhee;
	}
	else
		srez = cut_one(&((*str)[*tecyhee]), '\0', 0);
	k = prop_probel(srez);
	(*type) = (((*type) << 2) + (proverca(srez[k])));
	return (srez);
}

char				op_reg(char *str, t_chempion *ch, t_new_st_label *label, \
		t_op_strukt *new_op)
{
	int				n;
	unsigned char	type;
	int				tecyhee;
	char			*srez;
	int				kol;

	srez = NULL;
	n = 0;
	kol = 0;
	type = 0;
	while (n >= 0)
	{
		tecyhee = prop_probel(str);
		n = kol_sim(&str[tecyhee], SEPARATOR_CHAR);
		srez = op_reg3(n, &str, &tecyhee, &type);
		kol += 1;
		if ((proverca_registr(srez, ch, label, new_op)) < 0)
		{
			free(srez);
			return (-1);
		}
		(ch->tu)++;
		free(srez);
	}
	return (op_reg2(type, kol));
}

int					pars_stroca(t_chempion *ch, t_op_strukt *last_op, \
		t_new_st_label *label)
{
	char			*str;

	str = last_op->stroca;
	ch->mestnoe_smehenee = last_op->smechenee;
	ch->mestnoe_size = last_op->size;
	ch->code[ch->i] = last_op->name + 1;
	(ch->i)++;
	if (g_op_tab[last_op->name].code_type == 1)
	{
		ch->tu = (ch->i) + 1;
		if ((ch->code[ch->i] = op_reg(str, ch, label, last_op)) == -1)
			return (-1);
	}
	else
	{
		ch->tu = ch->i;
		if ((op_reg(str, ch, label, last_op)) == -1)
			return (-1);
	}
	ch->i = ch->tu;
	return (1);
}

int					trace_byte_code(t_chempion *ch, t_new_st_label *label, \
		t_op_strukt *op)
{
	t_op_strukt		*op_new;

	op_new = op;
	ch->i = 0;
	ch->code = (char*)malloc(sizeof(char) * ch->smehenee + 1);
	ch->code[ch->smehenee] = '\0';
	while (op_new)
	{
		if (pars_stroca(ch, op_new, label) < 0)
			return (-1);
		op_new = op_new->next;
	}
	return (1);
}

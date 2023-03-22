/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proverca_registra2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:17:49 by ksenaida          #+#    #+#             */
/*   Updated: 2021/02/11 21:15:15 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int					proverca_registr4(char *srez2, t_chempion *ch, \
t_new_st_label *label)
{
	long			k2;

	if ((k2 = proverca_instruction(srez2, ch, label)) < 0)
		k2 = 4294967296 + k2;
	if (ch->flag == -1)
	{
		free(srez2);
		return (-1);
	}
	byte_code(k2 >> 16, ch);
	(ch->tu)++;
	byte_code(k2, ch);
	free(srez2);
	return (1);
}

int					proverca_registr5(char *srez2, t_chempion *ch, \
t_new_st_label *label)
{
	int				k;

	if ((k = proverca_instruction(srez2, ch, label)) < 0)
		k = 65536 + k;
	if (ch->flag == -1)
	{
		free(srez2);
		return (-1);
	}
	byte_code(k, ch);
	free(srez2);
	return (1);
}

int					proverca_registr2(char *srez, t_chempion *ch, \
		t_new_st_label *label, t_op_strukt *new_op)
{
	char			*srez2;
	int				flag;

	flag = 0;
	if (srez[0] == ':')
	{
		flag = 1;
		srez2 = ft_strdup(&srez[1]);
	}
	else
		srez2 = ft_strdup(&srez[2]);
	ch->flag = 0;
	if (g_op_tab[new_op->name].size == 1 || flag == 1)
		return (proverca_registr5(srez2, ch, label));
	else
		return (proverca_registr4(srez2, ch, label));
	return (1);
}

int					proverca_registr3(char *srez, t_chempion *ch, \
		t_op_strukt *new_op)
{
	long			k2;
	int				k;

	k = 0;
	if (prop_probel(&(srez[1])) == -3 || (!ft_isdigit(srez[1])
		&& (srez[1] == '-' && !ft_isdigit(srez[2]))))
		return (-1);
	if (g_op_tab[new_op->name].size == 0)
	{
		k2 = ft_latoi(&srez[1]);
		if (k2 < 0)
			k2 = 4294967296 + k2;
		byte_code(k2 >> 16, ch);
		(ch->tu)++;
		byte_code(k2, ch);
	}
	if (((k = ft_atoi(&srez[1])) < 0) && g_op_tab[new_op->name].size == 1)
		k = 65536 + k;
	if (g_op_tab[new_op->name].size == 1)
		byte_code(k, ch);
	return (1);
}

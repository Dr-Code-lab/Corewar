/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_operation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:34:05 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/13 19:03:02 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int			analiz_registr2(char *srez, t_op_strukt **op, int kol)
{
	int		i;

	i = ft_strlen(srez) - 1;
	while (i >= 0 && (srez[i] == '\t' || (srez[i] == ' ')))
		i = i - 1;
	srez[i + 1] = '\0';
	if (srez[0] != ':' && prov(srez) < 0)
		return (-1);
	if (((g_op_tab[(*op)->name].reg[kol] & T_DIR) == T_DIR) &&
		g_op_tab[(*op)->name].size == 0)
		(*op)->size += T_DIR * 2;
	else if ((g_op_tab[(*op)->name].reg[kol] & T_DIR) == T_DIR)
		(*op)->size += T_DIR;
	else
		return (-1);
	return (1);
}

int			uslo(t_op_strukt **op, int sp, char *srez, int kol)
{
	if ((prov(&srez[sp]) >= 0 || srez[sp] == ':') &&
	(g_op_tab[(*op)->name].reg[kol] & T_IND) == T_IND)
		return (1);
	return (-1);
}

int			analiz_registr(char *srez, t_op_strukt **op, int kol)
{
	int		k;
	int		sp;

	sp = 0;
	if (kol + 1 > g_op_tab[(*op)->name].arg)
		return (-1);
	while (is_space_ch(srez, sp))
		sp++;
	if (srez[sp] == 'r')
	{
		if (srez[sp + 2] && (srez[sp + 1] == '-') && (srez[sp + 2] == '0'))
			return (-1);
		if (((g_op_tab[(*op)->name].reg[kol] & T_REG) == T_REG) && ((k =
		ft_atoi(&srez[sp + 1])) >= 0) && k < 100 && (prov(&srez[sp + 1]) >= 0))
			(*op)->size += T_REG;
		else
			return (-1);
	}
	else if (srez[sp] == DIRECT_CHAR)
		return (analiz_registr2(&(srez[sp + 1]), op, kol));
	else if (uslo(op, sp, srez, kol) > 0)
		(*op)->size += 2;
	else
		return (-1);
	return (1);
}

void		pars_register5(char *srez)
{
	int		i;

	i = ft_strlen(srez) - 1;
	while (i >= 0 && (srez[i] == '\t' || (srez[i] == ' ')))
		i = i - 1;
	srez[i + 1] = '\0';
}

int			pars_register(char *str, t_op_strukt **op, int n)
{
	int		tecyhee;
	char	*srez;
	int		kol;

	pars_register2(str, op);
	kol = 0;
	while (n >= 0)
	{
		if ((tecyhee = pars_register3(str, op)) < 0)
			return (-1);
		if ((n = kol_sim(&str[tecyhee], SEPARATOR_CHAR)) >= 0)
		{
			srez = cut_one(&str[tecyhee], SEPARATOR_CHAR, 0);
			tecyhee += (n + 1);
			str = str + tecyhee;
		}
		else
			srez = cut_one(&str[tecyhee], '\0', 0);
		pars_register5(srez);
		if (prop_srez(srez) < 0 || analiz_registr(srez, op, kol) < 0)
			return (free_and_return(srez, -1));
		kol++;
		free(srez);
	}
	return (1);
}

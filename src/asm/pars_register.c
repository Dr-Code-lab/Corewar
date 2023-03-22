/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_register.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ophuong <ophuong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:34:05 by ophuong           #+#    #+#             */
/*   Updated: 2021/02/13 21:02:02 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void		pars_register2(char *str, t_op_strukt **op)
{
	if (kol_sim(str, COMMENT_CHAR) != -1)
		str[kol_sim(str, COMMENT_CHAR)] = '\0';
	if (kol_sim(str, ALT_COMMENT_CHAR) != -1)
		str[kol_sim(str, ALT_COMMENT_CHAR)] = '\0';
	(*op)->stroca = ft_strdup(str);
}

int			pars_register3(char *str, t_op_strukt **op)
{
	int		tecyhee;

	if (((tecyhee = kol_sim_not(str, ' ')) < 0) || \
		(simvol(&str[tecyhee], SEPARATOR_CHAR) > g_op_tab[(*op)->name].arg))
		return (-1);
	return (tecyhee);
}

void		pars_register5(char *srez)
{
	int		i;

	i = ft_strlen(srez) - 1;
	while (i >= 0 && (srez[i] == '\t' || (srez[i] == ' ')))
		i = i - 1;
	srez[i + 1] = '\0';
}

void		pars_register4(char *str, int tecyhee, shar **srez)
{
	*srez = cut_one(&str[tecyhee], SEPARATOR_CHAR, 0);
	tecyhee += (n + 1);
	str = str + tecyhee;
	return (tecyhee);
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
			tecyhee = pars_register4(str, tecyhee);
		else
			srez = cut_one(&str[tecyhee], '\0', 0);
		pars_register5(srez);
		if (prop_srez(srez) < 0 || analiz_registr(srez, op, kol) < 0)
		{
			free(srez);
			return (-1);
		}
		kol++;
		free(srez);
	}
	return (1);
}

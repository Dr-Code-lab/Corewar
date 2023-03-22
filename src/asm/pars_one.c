/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:01:52 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/13 19:44:55 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		par3(char *line, t_chempion *ch, t_new_st_label **label, \
		t_op_strukt **op)
{
	if (line[0] == COMMENT_CHAR || line[0] == ALT_COMMENT_CHAR)
		return (1);
	if (pars_operation(line, ch, op, label) < 0)
		return (-1);
	ch->flag_label = 0;
	return (1);
}

int		pars_one2(char *line, t_chempion *ch)
{
	if (pars_name(line, ch) < 0)
		return (-1);
	return (1);
}

int		pars_one3(char *li, t_chempion *ch, t_new_st_label **labe, \
		t_op_strukt **op)
{
	int	probel;
	int	lab;
	int i;

	probel = prop_probel(li);
	lab = lab_ch(&(li[probel]));
	if (lab == -2 || lab == -1)
	{
		if (par3(&(li[probel]), ch, labe, op) < 0)
			return (-1);
	}
	else
	{
		li[lab] = '\0';
		if ((par_l(&(li[probel]), ch, labe)) < 0)
			return (-1);
		i = lab - probel + 1;
		while (li[i] && li[i] == ':')
			i++;
		if ((probel = prop_probel(&(li[i]))) == -3)
			return (1);
		if (par3(&(li[i + probel]), ch, labe, op) < 0)
			return (-1);
	}
	return (1);
}

char	*pars_one_else(char *li)
{
	char	*p;

	p = ft_strchr(li, '#');
	if (p != NULL)
		*p = '\0';
	while (*li == '\t' || *li == ' ')
		li++;
	return (li);
}

int		pars_one(char *li, t_chempion *ch, t_new_st_label **labe, \
		t_op_strukt **op)
{
	int		i;
	int		probel;

	i = 0;
	probel = prop_probel(li);
	if (probel == -3)
		return (1);
	if (li[probel] && li[probel] != ' ' && li[probel] != '\0' && \
			li[probel] != '\t' && li[probel] != '\n' && \
			li[probel] != COMMENT_CHAR && li[probel] != ALT_COMMENT_CHAR)
	{
		if (li[probel] == '.')
		{
			if (pars_one2(&(li[probel]), ch) < 0)
				return (-1);
		}
		else
		{
			li = pars_one_else(li);
			if (ch->flag == -1 || ch->kol_name_comment < 2 \
			|| pars_one3(li, ch, labe, op) < 0)
				return (-1);
		}
	}
	return (1);
}

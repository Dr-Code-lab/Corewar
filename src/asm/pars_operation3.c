/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_operation3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:23:54 by hlikely           #+#    #+#             */
/*   Updated: 2021/02/13 22:24:29 by hlikely          ###   ########.fr       */
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

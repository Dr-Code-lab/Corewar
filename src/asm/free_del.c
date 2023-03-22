/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:20:52 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/13 22:25:48 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void		free_op_struct(t_op_strukt *op)
{
	t_op_strukt		*op_next;

	while (op)
	{
		op_next = op->next;
		free(op->stroca);
		free(op);
		op = op_next;
	}
}

void		free_lab(t_new_st_label *label)
{
	t_new_st_label	*label_next;
	t_label			*lab;
	t_label			*lab_next;

	while (label)
	{
		lab = (t_label*)label->lab;
		label_next = label->next;
		free(label);
		while (lab)
		{
			lab_next = lab->next;
			free(lab->name);
			free(lab);
			lab = lab_next;
		}
		free(lab);
		label = label_next;
	}
}

int			free_and_return(char *line, int k)
{
	if (k != -1)
		ft_printf("number = %d   line = %s\n", k, line);
	free(line);
	return (-1);
}

int			is_space_ch(char *s, int a)
{
	if (s[a] == '\t' || s[a] == '\r' || s[a] == '\f' || s[a] == '\v' ||
		s[a] == ' ')
		return (1);
	else
		return (0);
}

int			prov(char *srez)
{
	int i;

	i = 0;
	if (srez[i] == '-')
		i++;
	if (srez[i] == '\0')
		return (-1);
	while (srez[i])
	{
		if (ft_isdigit(srez[i]))
			i++;
		else
			return (-1);
	}
	return (1);
}

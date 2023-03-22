/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:37:15 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/11 15:41:54 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		pars_name3(char *line, t_chempion *ch, int i)
{
	while (line[i] != '\0' && line[i] != '"')
	{
		ch->comment[ch->i] = line[i];
		ch->i++;
		i++;
	}
	while (ch->i < COMMENT_LENGTH)
	{
		ch->comment[ch->i] = 0;
		ch->i++;
	}
	if (line[i + 1] != '\0')
		return (-1);
	ch->i = 0;
	return (1);
}

int		pars_name2(char *line, t_chempion *ch, int i)
{
	while (line[i] != '\0' && line[i] != '"')
	{
		ch->comment[ch->i] = line[i];
		ch->i += 1;
		i++;
	}
	ch->comment[ch->i] = '\n';
	ch->i++;
	return (1);
}

int		pars_name4(char *line, t_chempion *ch, int n)
{
	while (line[n] != '\0' && line[n] != '"')
	{
		ch->name[ch->n] = line[n];
		ch->n += 1;
		n++;
	}
	ch->name[ch->n] = '\n';
	ch->n++;
	return (1);
}

int		pars_name5(char *line, t_chempion *ch, int n)
{
	while (line[n] != '\0' && line[n] != '"')
	{
		ch->name[ch->n] = line[n];
		ch->n++;
		n++;
	}
	while (ch->n < PROG_NAME_LENGTH)
	{
		ch->name[ch->n] = 0;
		ch->n++;
	}
	ch->n = 0;
	if (line[n + 1] != '\0')
		return (-1);
	return (1);
}

int		flag_name(char *line, t_chempion *ch, int n, int k)
{
	if (ch->flag == 2 && k == -1)
		return (pars_name2(line, ch, n));
	else if (ch->flag == 2)
		return (pars_name3(line, ch, n));
	if (ch->flag == 1 && k == -1)
		return (pars_name4(line, ch, n));
	else if (ch->flag == 1)
		return (pars_name5(line, ch, n));
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:14:11 by ksenaida          #+#    #+#             */
/*   Updated: 2021/02/13 22:07:02 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		read_name(t_chempion *ch, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0' && line[i] != '"')
		ch->comment[ch->i++] = line[i++];
	if (line[i] == '"')
	{
		if (line[i + 1] != '\0')
			return (-1);
		while (ch->i < COMMENT_LENGTH)
		{
			ch->comment[ch->i] = 0;
			ch->i++;
		}
		ch->i = 0;
		ch->prov = 5;
	}
	else
	{
		ch->comment[ch->i] = '\n';
		ch->i++;
	}
	return (1);
}

int		read_comment(t_chempion *ch, char *line)
{
	int n;

	n = 0;
	while (line[n] != '\0' && line[n] != '"')
		ch->name[ch->n++] = line[n++];
	if (line[n] == '"')
	{
		if (line[n + 1] != '\0')
			return (-1);
		while (ch->n < PROG_NAME_LENGTH)
		{
			ch->name[ch->n] = 0;
			ch->n++;
		}
		ch->n = 0;
		ch->prov = 5;
	}
	else
	{
		ch->name[ch->n] = '\n';
		ch->n++;
	}
	return (1);
}

int		tmpt(int tmp)
{
	if (tmp < 0)
		return (-1);
	return (1);
}

int		read_line_add(t_chempion *ch, char *line)
{
	if (ch->i != 0)
	{
		if (read_name(ch, line) < 0)
			return (free_and_return(line, -1));
	}
	else if (ch->n != 0)
	{
		if (read_comment(ch, line) < 0)
			return (free_and_return(line, -1));
	}
	return (1);
}

int		read_line(int fd, t_chempion *ch, t_new_st_label **label, \
		t_op_strukt **op)
{
	char	*line;
	int		k;
	int		probel;
	int		tmp;

	k = 0;
	while ((tmp = get_next_line(fd, &line)) > 0)
	{
		ch->prov = 1;
		if (ft_strlen(line) > COMMENT_LENGTH || ch->i > COMMENT_LENGTH \
		|| ch->n > PROG_NAME_LENGTH)
			return (free_and_return(line, k));
		if ((ch->i != 0 || ch->n != 0) && read_line_add(ch, line) < 0)
			return (-1);
		else if (ch->i == 0 && ch->n == 0 && ch->prov != 5)
		{
			k++;
			if ((probel = prop_probel(line)) != -3)
				if (pars_one(line, ch, label, op) < 0)
					return (free_and_return(line, k));
		}
		free(line);
	}
	return (tmpt(tmp));
}

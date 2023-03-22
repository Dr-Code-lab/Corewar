/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:33:46 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/13 19:20:35 by ksenaida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char		*cut_one(char *str, char c, int n)
{
	char	*srez;
	char	*srez2;
	int		n_line;

	n_line = kol_sim(&(str[n]), c);
	srez2 = ft_strdup(str);
	if (n_line != -1 && n_line != (int)ft_strlen(str))
		srez2[n_line] = '\0';
	srez = ft_strdup(srez2);
	free(srez2);
	return (srez);
}

int			proverca_label(char *str)
{
	int		i;
	int		k;
	char	*label_char;

	i = 0;
	label_char = LABEL_CHARS;
	while (str[i] != '\0')
	{
		k = 0;
		while (label_char[k] != '\0' && label_char[k] != str[i])
			k++;
		if (label_char[k] == '\0')
			return (-1);
		i++;
	}
	return (1);
}

int			par_l(char *line, t_chempion *ch, t_new_st_label **label)
{
	char	*srez;

	srez = ft_strdup(line);
	ch->flag = 3;
	if (zap_struct_ascii(ch, srez, label) < 0)
	{
		free(srez);
		return (-1);
	}
	free(srez);
	return (1);
}

int			pars_name_part_two(char *line, t_chempion *ch)
{
	int		len;
	int		probel;

	if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		if (ft_strlen(ch->name) != 0)
			return (-1);
		ch->flag = 1;
		len = ft_strlen(NAME_CMD_STRING);
	}
	else
	{
		if (ft_strlen(ch->comment) != 0)
			return (-1);
		ch->flag = 2;
		len = ft_strlen(COMMENT_CMD_STRING);
	}
	ch->kol_name_comment += 1;
	probel = prop_probel(&(line[len]));
	if (probel == -3 || line[probel + len] != '"')
		return (-1);
	return (flag_name(line, ch, probel + len + 1, \
	kol_sim(&(line[probel + len + 1]), '"')));
}

int			pars_name(char *line, t_chempion *ch)
{
	if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0 || \
				ft_strncmp(line, COMMENT_CMD_STRING, \
					ft_strlen(COMMENT_CMD_STRING)) == 0)
		return (pars_name_part_two(line, ch));
	return (-1);
}

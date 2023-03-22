/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_function2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:25:41 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/13 19:35:10 by ophuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		proverca(char c)
{
	if (c == 'r')
		return (REG_CODE);
	else if (c == '%')
		return (DIR_CODE);
	else
		return (IND_CODE);
	return (-1);
}

int		probels(char c)
{
	if (c == '\t' || c == '\r' || c == ' ' || c == '\v' || c == '%')
		return (1);
	return (0);
}

int		lab_ch(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != LABEL_CHAR)
	{
		if (probels(str[i]) == 1)
			return (-2);
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int		simvol(char *str, char c)
{
	int	i;
	int	kol;

	i = 0;
	kol = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			kol++;
		i++;
	}
	return (kol);
}

int		prop_srez(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != SEPARATOR_CHAR)
	{
		if (str[i] == ' ')
			if (prop_probel(&(str[i])) != -3)
				return (-1);
		i++;
	}
	return (1);
}

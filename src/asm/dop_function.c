/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:20:14 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/11 19:20:26 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		prop_probel(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == ' ' || \
				str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '\0')
		return (-3);
	return (i);
}

int		number_pr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ' && \
	str[i] != '\v' && str[i] != '\r')
		i++;
	if (str[i] == '\0')
		return (-3);
	return (i);
}

int		kol_sim_not(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int		kol_sim(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int		file_argv(char *str)
{
	if (str[ft_strlen(str) - 1] == 's' && str[ft_strlen(str) - 2] == '.')
		return (1);
	return (-1);
}

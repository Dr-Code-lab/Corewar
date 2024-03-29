/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 20:25:40 by hlikely           #+#    #+#             */
/*   Updated: 2021/02/10 19:21:54 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

int		get_adrs(t_koretko *koretko, int modif, int phantom_step)
{
	int	adrs;

	if (phantom_step == 1)
		adrs = koretko->position + koretko->ind_adrs + modif;
	else
		adrs = koretko->position + koretko->step + modif;
	adrs %= MEM_SIZE;
	if (adrs < 0)
		adrs += MEM_SIZE;
	return (adrs);
}

int		ft_atoi_only_dig(const char *str, t_cw *cw)
{
	long	res;

	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
			|| *str == ' ' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		output_error(6, cw);
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str)
	{
		if ((*str < '1') || (*str > '9'))
			output_error(6, cw);
		res = res * 10 + (*str - '0');
		if (res > MAX_PLAYERS)
			output_error(6, cw);
		str++;
	}
	return (int)(res);
}

int		has_cor(char *str)
{
	int		a;
	char	*s;

	a = ft_strlen(str);
	if (a > 4)
	{
		s = ft_strsub(str, a - 4, 4);
		if (ft_strcmp(s, ".cor") == 0)
		{
			free(s);
			return (1);
		}
		free(s);
	}
	return (0);
}

void	swap_kor(t_koretko **prev, t_koretko **kor)
{
	*prev = *kor;
	*kor = (*kor)->next;
}

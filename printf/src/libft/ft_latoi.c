/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:13:29 by heantoni          #+#    #+#             */
/*   Updated: 2021/02/10 22:25:59 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		pro(char *str)
{
	if (*str == ' ' || *str == '\n' || *str == '\v' || \
			(*str == '\t') || (*str == '\f') || (*str == '\r'))
		return (1);
	return (0);
}

static int		flag(char *str)
{
	int			fl;

	fl = 1;
	if (*str == '-')
		fl = -1;
	return (fl);
}

long			ft_latoi(char *str)
{
	long long	chuslo;
	int			fl;

	chuslo = 0;
	while (pro(str) == 1)
		str++;
	fl = flag(str);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		chuslo = chuslo * 10 + (*str - '0');
		str++;
	}
	return (fl * chuslo);
}

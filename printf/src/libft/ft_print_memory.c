/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:10:42 by hlikely           #+#    #+#             */
/*   Updated: 2021/02/10 22:22:00 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

void	ft_print_hex(unsigned char c)
{
	char *base;

	base = "0123456789abcdef";
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	ft_print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned char	*p;

	i = 0;
	p = (unsigned char*)addr;
	while (i < size)
	{
		j = 0;
		if (i == 0)
			ft_printf("0x0000 : ");
		else
			ft_printf("%0#6x : ", i);
		while (j < 64 && i + j < size)
		{
			ft_print_hex(p[i + j]);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i += 64;
	}
}

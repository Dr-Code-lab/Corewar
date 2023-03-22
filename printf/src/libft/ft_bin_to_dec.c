/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlikely <hlikely@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:08:14 by hlikely           #+#    #+#             */
/*   Updated: 2021/02/10 21:08:15 by hlikely          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bin_to_dec(const unsigned char *bin, int size)
{
	int i;
	int value;

	i = 0;
	value = 0;
	while (size)
	{
		value += ((bin[size - 1] & 255) << (8 * i));
		i++;
		size--;
	}
	return (value);
}

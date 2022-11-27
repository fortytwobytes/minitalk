/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:18:56 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/27 13:21:33 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr_b(unsigned int nbr, char *base, int *len)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (nbr < base_len)
		ft_putchar(base[nbr], len);
	else
	{
		ft_putnbr_b(nbr / base_len, base, len);
		ft_putchar(base[nbr % base_len], len);
	}
}

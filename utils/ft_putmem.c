/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:35:20 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/27 12:01:39 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putmem_hex(unsigned long int nbr, int *len)
{
	unsigned long int	base_len;
	char				*base;

	base_len = 16;
	base = "0123456789abcdef";
	if (nbr < base_len)
		ft_putchar(base[nbr % base_len], len);
	else
	{
		ft_putmem_hex(nbr / base_len, len);
		ft_putmem_hex(nbr % base_len, len);
	}
}

void	ft_putmem(void *p, int *len)
{
	unsigned long int	ptr;

	ptr = (unsigned long int)p;
	ft_putstr("0x", len);
	ft_putmem_hex(ptr, len);
}

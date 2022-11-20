/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <aarbaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:51:56 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/19 16:13:19 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int nbr, int *len)
{
	if (nbr < 10)
		ft_putchar(nbr + '0', len);
	else
	{
		ft_putnbr_u(nbr / 10, len);
		ft_putchar((nbr % 10) + '0', len);
	}
}

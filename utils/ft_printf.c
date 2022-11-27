/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:17:19 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/27 12:01:35 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_checks(va_list ap, const char c, int *len)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (c == 'u')
		ft_putnbr_u(va_arg(ap, unsigned int), len);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (c == 'x')
		ft_putnbr_b(va_arg(ap, size_t), "0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_b(va_arg(ap, size_t), "0123456789ABCDEF", len);
	else if (c == '%')
		ft_putchar('%', len);
	else if (c == 'p')
		ft_putmem(va_arg(ap, void *), len);
	else if (c == 'c')
		ft_putchar(va_arg(ap, int), len);
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && !str[1])
			break ;
		if (*str == '%')
		{
			str++;
			ft_checks(ap, *str, &len);
		}
		else
			ft_putchar(*str, &len);
		str++;
	}
	va_end(ap);
	return (len);
}

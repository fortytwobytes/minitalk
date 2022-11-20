/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <aarbaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:21:40 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/19 16:12:42 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_putnbr_u(unsigned int nbr, int *len);
void	ft_putnbr_b(unsigned int nbr, char *base, int *len);
void	ft_putmem(void *p, int *len);
int		ft_atoi(const char *str);

#endif
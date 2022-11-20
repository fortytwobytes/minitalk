/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anas <aarbaoui@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:09:53 by anas              #+#    #+#             */
/*   Updated: 2022/11/20 11:57:45 by anas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_error()
{
	ft_printf("%sError: %sWrong PID or Signal Error", RED, RESET);
	exit(0);
}

void	chartobin(unsigned char c, unsigned long pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				signal_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				signal_error();
		}
		c <<= 1;
		bit++;
		pause();
		usleep(100);
	}
}

void	send_message(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		chartobin(message[i], pid);
		i++;
	}
	chartobin('\0', pid);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("%s%sMessage sent%s", GREEN, BOLD, RESET);
		return ;
	}
	else if (sig == SIGUSR2)
	{
		return ;
	}
}
int main(int argc, char **argv)
{
	unsigned long	pid;

	if (argc != 3)
	{
		ft_printf("%sError: %sWrong number of arguments", RED, RESET);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_message(argv[2], pid);
	return (0);
}

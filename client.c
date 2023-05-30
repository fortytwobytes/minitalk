/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:09:53 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/05/30 18:03:19 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_error(void)
{
	ft_printf("%sError: %sWrong PID or Signal Error", RED, RESET);
	exit(-1);
}

void	chartobin(unsigned char byte, pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (byte & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				signal_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				signal_error();
		}
		byte <<= 1;
		bit++;
		pause();
		usleep(100);
	}
}

void	send_message(char *message, pid_t pid)
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
		ft_printf("\n%s%sMessage sent%s\n", GREEN, BOLD, RESET);
		return ;
	}
	else if (sig == SIGUSR2)
	{
		return ;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

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

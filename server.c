/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:15:19 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/16 18:50:27 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_banner(pid_t pid)
{
	ft_printf(",--.   ,--.,--.,--.  ,--.,--.,--------. ,---.  ,--.   ,--. ,--.\n");
	ft_printf("|   `.'   ||  ||  ,'.|  ||  |'--.  .--'/  O  \\ |  |   |  .'   /\n");
	ft_printf("|  |'.'|  ||  ||  |' '  ||  |   |  |  |  .-.  ||  |   |  .   '  \n");
	ft_printf("|  |   |  ||  ||  | `   ||  |   |  |  |  | |  ||  '--.|  |\\   \\\n");
	ft_printf("`--'   `--'`--'`--'  `--'`--'   `--'  `--' `--'`-----'`--' '--'\n");
	ft_printf("		      --- by aarbaoui ---\n");
	ft_printf("		      --- pid = %d ---\n", pid);
}

void	print_string(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits;
	static int	client_pid;
	static int	current_pid;
	
	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		bits = 0;
		c = 0;
	}
	if (sig == SIGUSR1)
		c = c << 1;
	else if (sig == SIGUSR2)
		c = (c << 1) + 1;
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			bits = 0;
			c = 0;
		}
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	struct sigaction	sa;

	pid = getpid();
	print_banner(pid);
	sa.sa_sigaction = print_string;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		pause();
	}
	return (0);
}

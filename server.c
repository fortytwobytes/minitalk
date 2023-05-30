/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:09:47 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/05/30 18:03:19 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_banner(pid_t pid)
{
	ft_printf("%s%s ███▄ ▄███▓██▓███▄    █ ██▄▄▄█████▓▄▄▄      ██▓    ██ ▄█▀\n",
		BOLD, RED);
	ft_printf("%s%s▓██▒▀█▀ ██▓██▒██ ▀█   █▓██▓  ██▒ ▓▒████▄   ▓██▒    ██▄█▒ \n",
		BOLD, RED);
	ft_printf("%s%s▓██    ▓██▒██▓██  ▀█ ██▒██▒ ▓██░ ▒▒██  ▀█▄ ▒██░   ▓███▄░ \n",
		BOLD, RED);
	ft_printf("%s%s▒██    ▒██░██▓██▒  ▐▌██░██░ ▓██▓ ░░██▄▄▄▄██▒██░   ▓██ █▄ \n",
		BOLD, RED);
	ft_printf("%s%s▒██▒   ░██░██▒██░   ▓██░██░ ▒██▒ ░ ▓█   ▓██░██████▒██▒ █▄\n",
		BOLD, RED);
	ft_printf("%s%s░ ▒░   ░  ░▓ ░ ▒░   ▒ ▒░▓   ▒ ░░   ▒▒   ▓▒█░ ▒░▓  ▒ ▒▒ ▓▒\n",
		BOLD, RED);
	ft_printf("%s%s░  ░      ░▒ ░ ░░   ░ ▒░▒ ░   ░     ▒   ▒▒ ░ ░ ▒  ░ ░▒ ▒░\n",
		BOLD, RED);
	ft_printf("%s%s░      ░   ▒ ░  ░   ░ ░ ▒ ░ ░       ░   ▒    ░ ░  ░ ░░ ░ \n",
		BOLD, RED);
	ft_printf("%s%s       ░   ░          ░ ░               ░  ░   ░  ░  ░   \n\
		%s", BOLD, RED, RESET);
	ft_printf("													 		\n");
	ft_printf("%s%s		by: aarbaoui %s| %sPID: %d%s\n",
		BOLD, GREEN, YELLOW, GREEN, pid, RESET);
}

void	sigerror(pid_t clientpid)
{
	ft_printf("%sError:%s Cannot send recognition signal to client PID: %d",
		RED, RESET, clientpid);
	exit(-1);
}

void	sighandlehelp(char *byte, int *bits, pid_t *clientpid)
{
	write(1, byte, 1);
	if (*byte == '\0')
	{
		write(1, "\n", 1);
		*byte = 0;
		if (kill(*clientpid, SIGUSR1) == -1)
			sigerror(*clientpid);
		return ;
	}
	*bits = 0;
}

void	sighandle(int sig, siginfo_t *info, void *context)
{
	static int		bits;
	static char		bytes;
	static pid_t	clientpid;
	static pid_t	workingpid;

	(void)context;
	if (!clientpid)
		clientpid = info->si_pid;
	workingpid = info->si_pid;
	if (clientpid != workingpid)
	{
		clientpid = workingpid;
		bits = 0;
		bytes = 0;
	}
	bytes = bytes | (sig == SIGUSR2);
	bits++;
	if (bits == 8)
		sighandlehelp(&bytes, &bits, &clientpid);
	bytes <<= 1;
	usleep(100);
	kill(clientpid, SIGUSR2);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_print_banner(pid);
	sa.sa_sigaction = sighandle;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}

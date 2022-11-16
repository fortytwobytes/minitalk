/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:15:19 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/16 15:49:16 by aarbaoui         ###   ########.fr       */
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

void	print_string(int sig)
{
	static char	c;
	static int	i;

	if (sig == SIGUSR1)
		c = c << 1;
	else if (sig == SIGUSR2)
		c = (c << 1) + 1;
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			i = 0;
			c = 0;
		}
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	struct sigaction	sa;
	
	sa.sa_handler = print_string;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	print_banner(pid);
	while (1)
		pause();
	return (0);
}

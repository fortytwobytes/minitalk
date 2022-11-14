/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:15:19 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/14 18:44:36 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	print_string(int sig)
{
	static int				i;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c = c << 1;
	else if (sig == SIGUSR2)
		c = (c << 1) + 1;
	else
		printf("Error: signal not supported"); 
		return ;
	i++;
	if (i == 8)
	{	
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf(",--.   ,--.,--.,--.  ,--.,--.,--------. ,---.  ,--.   ,--. ,--.\n");
	printf("|   `.'   ||  ||  ,'.|  ||  |'--.  .--'/  O  \\ |  |   |  .'   /\n");
	printf("|  |'.'|  ||  ||  |' '  ||  |   |  |  |  .-.  ||  |   |  .   '  \n");
	printf("|  |   |  ||  ||  | `   ||  |   |  |  |  | |  ||  '--.|  |\\   \\\n");
	printf("`--'   `--'`--'`--'  `--'`--'   `--'  `--' `--'`-----'`--' '--'\n");
	printf("		      --- by aarbaoui ---\n");
	printf("		      --- pid = %d ---\n", pid);
	signal(SIGUSR1, print_string);
	signal(SIGUSR2, print_string);
	while (1)
		pause();
	return (0);
}

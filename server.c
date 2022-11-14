/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:15:19 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/14 16:44:55 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	save_to_string(int sig)
{
	static int i = 0;
	static unsigned char c = 0;

	if (sig == SIGUSR1)
		c = c << 1;
	else if (sig == SIGUSR2)
		c = (c << 1) + 1;
	i++;
	if (i == 8)
	{	
		i = 0;
		c = 0;
	}
}


int main(void)
{
	pid_t	pid;
	
	pid = getpid();
	printf(",--.   ,--.,--.,--.  ,--.,--.,--------. ,---.  ,--.   ,--. ,--.\n");
	printf("|   `.'   ||  ||  ,'.|  ||  |'--.  .--'/  O  \\ |  |   |  .'   /\n");
	printf("|  |'.'|  ||  ||  |' '  ||  |   |  |  |  .-.  ||  |   |  .   '  \n");
	printf("|  |   |  ||  ||  | `   ||  |   |  |  |  | |  ||  '--.|  |\\   \\\n");
	printf("`--'   `--'`--'`--'  `--'`--'   `--'  `--' `--'`-----'`--' '--'\n");
	printf("		      --- by aarbaoui ---\n");
	printf("		      --- pid = %d ---\n" , pid);
	signal(SIGUSR1, save_to_string);
	signal(SIGUSR2, save_to_string);
	while (1)
   		pause();
	return (0);
}
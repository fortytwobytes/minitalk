/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:15:23 by aarbaoui          #+#    #+#             */
/*   Updated: 2022/11/14 18:37:32 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_bits(unsigned char octet, pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (octet & 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		octet <<= 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		while (argv[2][i])
		{
			print_bits(argv[2][i], pid);
			i++;
		}
		print_bits('\n', pid);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:34:12 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/15 19:31:14 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	char_to_bin(char c, int pid)
{
	int	i;
	int wait;

	i = 8;
	wait = 0;
	while (i >= 0)
	{
		if ((c & 1) == 1)
			kill(pid, SIGUSR1);
		else if ((c & 1) == 0)
			kill(pid, SIGUSR2);
		c = c << 1;
		i--;
	}
}

void	client_sig_handler(int signum)
{
	
}

int	main(int argc, char **argv)
{
	struct sigaction	ca;
	int					pid;
	int					i;

	if (argc != 3)
		exit (1);
	i = 0;
	pid = ft_atoi(argv[1]);
	sigemptyset(&ca.sa_mask);
	ca.sa_handler = client_sig_handler;
	ca.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ca, NULL);
	sigaction(SIGUSR2, &ca, NULL);
	// envoyer bit par bit dans une fonction tant que argv[2][i] exist
	while (argv[2][i])
		char_to_bin(argv[2][i++], pid);
	char_to_bin(argv[2][i], pid);
}

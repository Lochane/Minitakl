/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:34:12 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/16 18:18:51 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int g_g;

void	char_to_bin(char c, int pid)
{
	int	i;
	int wait;

	i = 7;
	wait = 0;
	while (i >= 0)
	{
		if (((c >> i) & 1))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_g == 0)
			usleep(200);
		g_g = 0;
		i--;
	}
}

void	client_sig_handler(int signum, siginfo_t *info, void *content)
{
	(void)info;
	(void)content;
	(void)signum;
	g_g = 1;
	// if (signum == SIGUSR1)
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
	ca.sa_sigaction = client_sig_handler;
	ca.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &ca, NULL);
	sigaction(SIGUSR2, &ca, NULL);
	while (argv[2][i])
		char_to_bin(argv[2][i++], pid);
	char_to_bin(argv[2][i], pid);
return (1);
}

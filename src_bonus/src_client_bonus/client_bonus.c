/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:34:12 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/19 19:51:19 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	g_g;

void	wait(void)
{
	while (g_g == 0)
		usleep(100);
	g_g = 0;
}

void	error_msg(void)
{
	ft_printf("No respond from server\n");
	exit (0);
}

void	char_to_bin(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1))
		{
			if (kill(pid, SIGUSR1) == -1)
				error_msg();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_msg();
		}
		wait();
		i--;
	}
}

void	client_sig_handler(int signum, siginfo_t *info, void *content)
{
	(void)info;
	(void)content;
	g_g = 1;
	if (signum == SIGUSR2)
		ft_printf("Message received\n");
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

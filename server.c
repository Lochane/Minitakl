/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:20:19 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/16 20:40:48 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	stash_and_print(char c, char *stash)
{
	if (c == '\0')
		ft_printf("%s\n", stash);
}

void	bin_to_char(int signum, char *c, int pid)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}

void	serv_sig_handler(int signum, siginfo_t *info, void *content)
{
	static char c;
	static int	byte_count;
	static int	pid;
	static	char *stash;
	static	int	size = 100;
	static	int	i;

	(void)content;
	stash = ft_calloc(sizeof(char *), size);
	pid = info->si_pid;
	bin_to_char(signum, &c, pid);
	byte_count++;
	if (byte_count == 8)
	{
		byte_count = 0;
		if (!c)
			kill(pid, SIGUSR1);
		stash[i++] = c;
		stash_and_print(c, stash);
		// i++;
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = serv_sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (1);
}

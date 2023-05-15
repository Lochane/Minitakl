/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:20:19 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/15 19:28:30 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	serv_sig_handler(int signum, siginfo_t *info, void *content)
{
	// faire la conversion binaire char
	// if (signum == SIGUSR1)
		printf("lol");
	// gerer la recetpion du signal
	// stocker le caractere recu dans une static et print cette static quand 
	// on arrive a /0 ou /n
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &serv_sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (1);
}

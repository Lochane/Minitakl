/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:46:44 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/19 18:48:54 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "../../libft/libft.h"

void	wait(void);
void	char_to_bin(char c, int pid);
void	client_sig_handler(int signum, siginfo_t *info, void *content);
void	error_msg(void);

#endif
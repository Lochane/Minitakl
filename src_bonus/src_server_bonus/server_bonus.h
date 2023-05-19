/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:20:12 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/19 19:51:01 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include "../../libft/libft.h"

typedef struct s_lst
{
	char				content;
	struct s_lst		*next;
}	t_lst;

void	ft_delone(t_lst *lst, void (*del)(void*));
void	ft_clear(t_lst **lst, void (*del)(void*));
void	ft_add_back(t_lst **lst, t_lst *new);
t_lst	*ft_newlst(char content);
void	print_lst(t_lst *data);
int		ft_sizelst(t_lst *lst);

void	cat_and_print(t_lst *lst);
void	stash(char c, t_lst **lst);
void	bin_to_char(int signum, char *c);
void	serv_sig_handler(int signum, siginfo_t *info, void *content);

#endif
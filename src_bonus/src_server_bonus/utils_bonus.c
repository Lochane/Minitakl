/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:13:24 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/19 19:47:24 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	ft_delone(t_lst *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	free (lst);
}

void	ft_clear(t_lst **lst, void (*del)(void*))
{
	t_lst	*temp;

	if (!lst || !del || !*lst)
		return ;
	while (lst && (*lst))
	{
		temp = (*lst)->next;
		ft_delone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_add_back(t_lst **lst, t_lst *new)
{
	t_lst	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
	if (lst && (*lst))
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}

t_lst	*ft_newlst(char content)
{
	t_lst	*liste;

	liste = malloc(sizeof(t_lst));
	if (!liste)
		return (NULL);
	liste->content = content;
	liste->next = NULL;
	return (liste);
}

void	print_lst(t_lst *data)
{
	while (data)
	{
		ft_printf("%c", data->content);
		data = data->next;
	}
	ft_printf("\n");
}

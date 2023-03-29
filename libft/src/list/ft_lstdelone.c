/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:31:47 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 12:20:21 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	lst->next = NULL;
	free(lst);
}

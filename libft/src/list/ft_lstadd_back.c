/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 16:10:42 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 10:52:29 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstptr;

	if (!new || !lst)
		return ;
	if (! *lst)
	{
		*lst = new;
		return ;
	}
	lstptr = ft_lstlast(*lst);
	lstptr->next = new;
}

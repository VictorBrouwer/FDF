/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 11:41:33 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 10:23:29 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*linklist;

	linklist = malloc(sizeof(t_list));
	if (!linklist)
		return (NULL);
	linklist->content = content;
	linklist->next = NULL;
	return (linklist);
}

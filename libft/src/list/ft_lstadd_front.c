/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 11:55:44 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 15:08:15 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*l1;
// 	t_list	*l2;
// 	t_list	*l3;

// 	l1 = ft_lstnew("hello");
// 	l2 = ft_lstnew("chavert");
// 	l3 = ft_lstnew("how are you");
// 	printf("before: %p", l1->next);
// 	ft_lstadd_front(&l1, l2);
// 	printf("\nafter: %p", l1->next);
// 	// ft_lstadd_front(&l1, l3);
// 	// printf("element 3: %s", l1->content);
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:04:46 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/23 10:19:50 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

t_points_link	*link_add_back(t_points_link **points, \
			t_points_link *new, t_points_link *last_node)
{
	if (!*points)
		*points = new;
	if (!points || !new)
		return (NULL);
	if (last_node != NULL)
		last_node->next = new;
	return (new);
}

t_points_link	*get_last_link(t_points_link *point)
{
	if (!point)
		error();
	while (point->next != NULL)
		point = point->next;
	return (point);
}

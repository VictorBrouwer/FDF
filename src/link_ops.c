/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:04:46 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/30 14:22:38 by vbrouwer         ###   ########.fr       */
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

void	check_values(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_is_fdf_char(s[i]) == 0)
			error();
		i++;
	}
}

int	ft_is_fdf_char(int c)
{
	if ((c >= 'A' && c <= 'F') || (c >= 'a' & c <= 'f')
		|| (c >= '0' && c <= '9') || c == ',' || c == 'x' || c == '-')
		return (1);
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:12:13 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/22 14:49:07 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h> 

void	error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	clean_up_split(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

void	clean_up_link_list(t_points_link **list)
{
	t_points_link	*temp;
	t_points_link	*node;

	node = *list;
	while (node != NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*list = NULL;
}

void	clean_up_arr(t_point **point_arr, t_map *map)
{
	int	y;

	y = 0;
	while (y < map->num_lines)
	{
		if (point_arr != NULL)
			free(point_arr[y]);
		y++;
	}
	free(point_arr);
}

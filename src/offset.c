/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:28:16 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/23 11:22:54 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fdf.h>

void	get_x_offset(t_map *map)
{
	int	most_left_x;
	int	most_right_x;
	int	map_width;

	get_iso_values(map, &map->points[map->num_lines - 1][0]);
	get_iso_values(map, &map->points[0][map->num_columns - 1]);
	most_left_x = map->points[map->num_lines - 1][0].iso_x;
	most_right_x = map->points[0][map->num_columns - 1].iso_x;
	map_width = calc_map_width(most_right_x, most_left_x);
	while (map_width > WIDTH)
	{
		map->scale--;
		get_iso_values(map, &map->points[map->num_lines - 1][0]);
		get_iso_values(map, &map->points[0][map->num_columns - 1]);
		most_left_x = map->points[map->num_lines - 1][0].iso_x;
		most_right_x = map->points[0][map->num_columns - 1].iso_x;
		map_width = calc_map_width(most_right_x, most_left_x);
	}
	map->x_offset = ((WIDTH - map_width) / 2) + get_abs(most_left_x);
}

int	calc_map_width(int most_right_x, int most_left_x)
{
	if (most_left_x < 0)
		return (most_right_x + get_abs(most_left_x));
	else
		return (most_right_x - most_left_x);
}

void	get_y_offset(t_map *map)
{
	int	map_height;
	int	upper_y;
	int	lower_y;

	map->y_offset = 0;
	get_iso_values(map, &map->points[0][0]);
	get_iso_values(map, &map->points[map->num_lines - 1][map->num_columns - 1]);
	upper_y = map->points[0][0].iso_y;
	lower_y = map->points[map->num_lines - 1][map->num_columns - 1].iso_y;
	map_height = calc_map_height(upper_y, lower_y);
	while (map_height > (HEIGHT - BORDER))
	{
		map->scale--;
		get_iso_values(map, &map->points[0][0]);
		get_iso_values(map, \
		&map->points[map->num_lines - 1][map->num_columns - 1]);
		upper_y = map->points[0][0].iso_y;
		lower_y = map->points[map->num_lines - 1][map->num_columns - 1].iso_y;
		map_height = calc_map_height(upper_y, lower_y);
	}
	if (upper_y < 0)
		map->y_offset = ((HEIGHT - map_height) / 2) + get_abs(upper_y);
	else
		map->y_offset = ((HEIGHT - map_height) / 2) - upper_y;
}

int	calc_map_height(int upper_y, int lower_y)
{
	if (upper_y < 0)
		return (lower_y + get_abs(upper_y));
	else
		return (lower_y - upper_y);
}

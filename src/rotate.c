/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:11:50 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/28 14:51:26 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	get_iso_values(t_map *map, t_point *point)
{
	rotate_around_x(point, map->x_angle, map);
	rotate_around_y(point, map->y_angle, map);
	rotate_around_z(point, map->z_angle);
	point->iso_x = (point->rot_x - point->rot_y) * cos(0.523599) + \
	map->x_offset;
	point->iso_y = (point->rot_x + point->rot_y) * sin(0.523599);
	point->iso_y -= (map->points[point->y][point->x].height * \
	(map->scale / 10));
	point->iso_y += map->y_offset + (map->height_changer * point->height);
}

void	rotate_around_x(t_point *point, float x_angle, t_map *map)
{
	int	y;
	int	z;

	y = (point->y - (map->num_lines / 2)) * map->scale;
	z = point->height * map->scale;
	point->rot_y = y * cos(x_angle) - z * sin(x_angle);
	point->rot_z = y * sin(x_angle) + z * cos(x_angle);
}

void	rotate_around_y(t_point *point, float y_angle, t_map *map)
{
	int	x;

	x = (point->x - (map->num_columns / 2)) * map->scale;
	point->rot_x = x * cos(y_angle) + point->rot_z * sin(y_angle);
	point->rot_z = -x * sin(y_angle) + point->rot_z * cos(y_angle);
}

void	rotate_around_z(t_point *point, float z_angle)
{
	int	x;
	int	y;

	x = point->rot_x;
	y = point->rot_y;
	point->rot_x = x * cos(z_angle) - y * sin(z_angle);
	point->rot_y = -x * sin(z_angle) + y * cos(z_angle);
}

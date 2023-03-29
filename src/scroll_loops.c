/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_loops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:40:22 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/29 11:08:33 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	my_scroll_hooks(double xdelta, double ydelta, void *map)
{
	t_map	*map_copy;
	t_map	old_map;

	map_copy = (t_map *) map;
	old_map = *(t_map *) map;
	(void) xdelta;
	if (ydelta > 0)
		map_copy->scale += 3;
	else if (ydelta < 0)
		map_copy->scale -= 3;
	if (memcmp(map_copy, &old_map, sizeof(t_map)) != 0)
	{
		ft_bzero(map_copy->img->pixels, \
		map_copy->img->width * map_copy->img->height * sizeof(u_int32_t));
		render_map(map_copy);
	}
}

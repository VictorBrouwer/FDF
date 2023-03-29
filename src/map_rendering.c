/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:51:41 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/28 14:24:40 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<fdf.h>

void	render_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->num_lines)
	{
		x = 0;
		while (x < map->num_columns - 1)
		{
			draw_line(map, &map->points[y][x], &map->points[y][x + 1]);
			if (y < map->num_lines - 1)
				draw_line(map, &map->points[y][x], &map->points[y + 1][x]);
			x++;
		}
		if (y < map->num_lines - 1)
			draw_line(map, &map->points[y][x], &map->points[y + 1][x]);
		y++;
	}
}

void	draw_line(t_map *map, t_point *p0, t_point *p1)
{
	t_draw	draw;
	int		err2;

	get_iso_values(map, p0);
	get_iso_values(map, p1);
	draw = init_draw(p0, p1);
	while (draw.x_pos != p1->iso_x && draw.y_pos != p1->iso_y)
	{
		if (check_bounds(draw.x_pos, draw.y_pos) == 1)
			mlx_put_pixel(map->img, draw.x_pos, draw.y_pos, \
							calc_col_gradient(p0, p1, draw));
		err2 = draw.error * 2;
		if (err2 >= draw.delta_y)
		{
			draw.error = draw.error + draw.delta_y;
			draw.x_pos = draw.x_pos + draw.x_sign;
		}
		if (err2 <= draw.delta_x)
		{
			draw.error = draw.error + draw.delta_x;
			draw.y_pos = draw.y_pos + draw.y_sign;
		}
	}
}

t_draw	init_draw(t_point *p0, t_point *p1)
{
	t_draw	draw;

	draw.delta_x = get_abs(p1->iso_x - p0->iso_x);
	draw.delta_y = -get_abs(p1->iso_y - p0->iso_y);
	draw.x_pos = p0->iso_x;
	draw.y_pos = p0->iso_y;
	draw.x_sign = ternary(p1->iso_x > p0->iso_x, 1, -1);
	draw.y_sign = ternary(p1->iso_y > p0->iso_y, 1, -1);
	draw.error = draw.delta_x + draw.delta_y;
	return (draw);
}

void	create_background(mlx_t *mlx)
{
	int			i;
	int			j;
	mlx_image_t	*background;

	background = mlx_new_image(mlx, WIDTH, HEIGHT);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(background, j, i, 0x000000FF);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, background, 0, 0);
}

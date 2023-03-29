/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:59:08 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/28 14:29:03 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	mlx_start(t_map *map)
{
	map->mlx = mlx_init(WIDTH, HEIGHT, "Hello FDF!", true);
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->scale = 40;
	create_background(map->mlx);
	get_x_offset(map);
	get_y_offset(map);
	render_map(map);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	mlx_loop_hook(map->mlx, &my_hooks, map);
	mlx_scroll_hook(map->mlx, &my_scroll_hooks, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
}

void	my_hooks(void *map)
{
	t_map	*map_copy;
	t_map	old_map;

	map_copy = (t_map *) map;
	old_map = *(t_map *) map;
	pos_and_size_loop(map_copy);
	angle_loop(map_copy);
	close_loop(map_copy->mlx);
	if (memcmp(map_copy, &old_map, sizeof(t_map)) != 0)
	{
		ft_bzero(map_copy->img->pixels, \
		map_copy->img->width * map_copy->img->height * sizeof(u_int32_t));
		render_map(map_copy);
	}
}

void	angle_loop(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_X))
		map->x_angle += 0.05;
	if (mlx_is_key_down(map->mlx, MLX_KEY_S))
		map->x_angle -= 0.05;
	if (mlx_is_key_down(map->mlx, MLX_KEY_Y))
		map->y_angle += 0.05;
	if (mlx_is_key_down(map->mlx, MLX_KEY_T))
		map->y_angle -= 0.05;
	if (mlx_is_key_down(map->mlx, MLX_KEY_Z))
		map->z_angle += 0.05;
	if (mlx_is_key_down(map->mlx, MLX_KEY_A))
		map->z_angle -= 0.05;
}

void	pos_and_size_loop(t_map *map)
{
	if (mlx_is_key_down(map->mlx, MLX_KEY_EQUAL))
		map->scale += 3;
	if (mlx_is_key_down(map->mlx, MLX_KEY_MINUS))
		map->scale -= 3;
	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
		map->x_offset -= 10;
	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
		map->x_offset += 10;
	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
		map->y_offset += 10;
	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
		map->y_offset -= 10;
	if (mlx_is_key_down(map->mlx, MLX_KEY_U))
		map->height_changer --;
	if (mlx_is_key_down(map->mlx, MLX_KEY_D))
		map->height_changer ++;
}

void	close_loop(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_C) || mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

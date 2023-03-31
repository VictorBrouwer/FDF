/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:51:14 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/31 11:03:02 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h> 

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		error();
	fd = check_filename(argv[1]);
	if (fd < 0)
		error();
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		error();
	parse_map(fd, map);
	mlx_start(map);
	clean_up_arr(map->points, map);
	free(map);
	close(fd);
	return (0);
}

int	check_filename(char *map_name)
{
	int	x;

	if (ft_strlen(map_name) < 4)
		error();
	x = ft_strlen(map_name) - 4;
	if (ft_strncmp(&map_name[x], ".fdf", 4) != 0)
		error();
	return (open(map_name, O_RDONLY));
}

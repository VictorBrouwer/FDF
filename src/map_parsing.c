/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:59:30 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/30 14:10:35 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	parse_map(int fd, t_map *map)
{
	char			*line;
	char			**str_arr;
	t_points_link	*old_point;

	line = get_next_line(fd);
	if (!line)
		error();
	map->point_list = ft_calloc(1, sizeof(t_points_link *));
	if (!map->point_list)
		error();
	map->num_lines = 0;
	old_point = NULL;
	while (line != NULL)
	{
		str_arr = ft_split(line, ' ');
		free(line);
		old_point = add_points(str_arr, map, old_point);
		clean_up_split(str_arr);
		line = get_next_line(fd);
		map->num_lines++;
	}
	prepare_array(map);
	free(map->point_list);
}

t_points_link	*add_points(char **str_arr, t_map *map, \
								t_points_link *old_point)
{
	int				i;
	t_points_link	*new_point;

	i = 0;
	while (str_arr[i] && str_arr[i][0] != '\n')
	{
		check_values(str_arr[i]);
		new_point = ft_calloc(1, sizeof(t_points_link));
		if (!new_point)
			error();
		new_point->height = ft_atoi_prot(str_arr[i]);
		if (ft_str_comma_finder(str_arr[i], ',') != NULL)
			new_point->color = get_color(ft_str_comma_finder(str_arr[i], ','));
		else
			new_point->color = get_color(NULL);
		new_point->column = i;
		new_point->row = map->num_lines;
		old_point = link_add_back(map->point_list, new_point, old_point);
		map->total_points++;
		i++;
	}
	if (map->num_columns < i)
		map->num_columns = i;
	return (old_point);
}

void	prepare_array(t_map *map)
{
	int				i;
	t_points_link	*list_pointer;

	list_pointer = *map->point_list;
	map->points = ft_calloc(map->num_lines, sizeof(t_point *));
	if (!map->points)
		error();
	i = 0;
	while (i < map->num_lines)
	{
		map->points[i] = ft_calloc(map->num_columns, sizeof(t_point));
		if (!map->points[i])
			error();
		i++;
	}
	fill_2d_array(map, list_pointer);
}

void	fill_2d_array(t_map *map, t_points_link *list_pointer)
{	
	int	i;
	int	j;

	i = 0;
	while (i < map->num_lines)
	{
		j = 0;
		while (j < map->num_columns)
		{
			map->points[i][j].x = j;
			map->points[i][j].y = i;
			map->points[i][j].height = list_pointer->height;
			map->points[i][j].color = list_pointer->color;
			if (list_pointer->next)
				list_pointer = list_pointer->next;
			j++;
		}
		i++;
	}
	clean_up_link_list(map->point_list);
}

char	*ft_str_comma_finder(const char *s, char c)
{
	unsigned int	x;
	char			*p;

	p = (char *) s;
	x = 0;
	while (p[x])
	{
		if (p[x] == c)
			return (&p[x + 1]);
		x++;
	}
	if (p[x] == c)
		return (&p[x]);
	else
		return (NULL);
}

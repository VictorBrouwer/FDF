/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:52:20 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/29 11:20:45 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include <unistd.h>
# include"../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define BORDER 50

typedef struct s_draw
{
	int						x_pos;
	int						y_pos;
	int						delta_x;
	int						delta_y;
	int						x_sign;
	int						y_sign;
	int						error;
}							t_draw;

typedef struct s_point
{
	int						height;
	int						x;
	int						y;
	u_int32_t				color;
	int						iso_x;
	int						iso_y;
	int						rot_x;
	int						rot_y;
	int						rot_z;
}							t_point;

typedef struct s_points_link
{
	int						row;
	int						column;
	int						height;
	u_int32_t				color;
	struct s_points_link	*next;
}							t_points_link;

typedef struct s_map
{
	int						num_columns;
	int						num_lines;
	int						total_points;
	int						scale;
	int						x_offset;
	int						y_offset;
	float					x_angle;
	float					y_angle;
	float					z_angle;
	t_point					**points;
	int						height_changer;
	t_points_link			**point_list;
	mlx_image_t				*img;
	mlx_t					*mlx;
}							t_map;

typedef struct s_rot
{
	int						x_origin;
	int						y_origin;
	int						x_0;
	int						y_0;
	int						z_0;
	int						x_1;
	int						y_1;
	int						z_1;
}							t_rot;

void			error(void);
int				check_filename(char *map_name);
void			parse_map(int fd, t_map *map);
int				count_elements(char **str_array);
int				ft_atoi_prot(const char *str);
t_points_link	*add_points(char **str_arr, t_map *map, \
				t_points_link *old_point);
t_points_link	*link_add_back(t_points_link **points, \
				t_points_link *new, t_points_link *last_node);
t_points_link	*get_last_link(t_points_link *point);
void			show_map(t_map *map);
void			prepare_array(t_map *map);
void			fill_2d_array(t_map *map, t_points_link *list_pointer);
void			mlx_start(t_map *map);
void			create_background(mlx_t *mlx);
void			render_map(t_map *map);
int				get_abs(int x);
int				check_bounds(int x, int y);
int				ternary(int statement, int true_out, int false_out);
t_draw			init_draw(t_point *p0, t_point *p1);
void			draw_line(t_map *map, t_point *p0, t_point *p1);
void			change_to_iso(t_map *map);
char			*ft_str_comma_finder(const char *s, char c);
u_int32_t		get_color(char *str);
u_int32_t		a_to_hex(char *str);
void			get_x_offset(t_map *map);
int				calc_map_width(int most_right_x, int most_left_x);
void			get_y_offset(t_map *map);
int				calc_map_height(int upper_y, int lower_y);
void			clean_up_split(char **str_arr);
void			clean_up_link_list(t_points_link **list);
void			clean_up_arr(t_point **point_arr, t_map *map);
u_int32_t		calc_col_gradient(t_point *p0, t_point *p1, t_draw draw);
float			get_percent(int start, int end, int curr);
int				calc_new_col(float percent, int red0, int red1);
u_int32_t		combine_rgb(int r, int g, int b);
void			change_height_positive(t_map *map);
void			change_height_negative(t_map *map);
void			get_iso_values(t_map *map, t_point *point);
void			rotate_around_x(t_point *point, float x_angle, t_map *map);
void			rotate_around_y(t_point *point, float y_angle, t_map *map);
void			rotate_around_z(t_point *point, float z_angle);
void			my_hooks(void *map);
void			pos_and_size_loop(t_map *map);
void			angle_loop(t_map *map);
void			close_loop(mlx_t *mlx);
void			my_scroll_hooks(double xdelta, double ydelta, void *param);

#endif
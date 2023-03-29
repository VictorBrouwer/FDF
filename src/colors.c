/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:45:53 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/23 10:19:03 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

u_int32_t	combine_rgb(int r, int g, int b)
{
	return ((r << 24 | g << 16 | b << 8) | 0xFF);
}

int	calc_new_col(float percent, int col0, int col1)
{
	return (((1 - percent) * col0) + (percent * col1));
}

float	get_percent(int start, int end, int curr)
{
	float	res;
	float	start_f;
	float	end_f;
	float	curr_f;

	start_f = (float)start;
	end_f = (float)end;
	curr_f = (float)curr;
	res = (curr_f - start_f) / (end_f - start_f);
	return (res);
}

u_int32_t	calc_col_gradient(t_point *p0, t_point *p1, t_draw draw)
{
	float		percent;
	int			new_red;
	int			new_green;
	int			new_blue;

	if (p0->color == p1->color)
		return (p0->color);
	if (draw.delta_x > draw.delta_y)
		percent = get_percent(p0->iso_x, p1->iso_x, draw.x_pos);
	else
		percent = get_percent(p0->iso_y, p1->iso_y, draw.y_pos);
	new_red = calc_new_col(percent, ((p0->color >> 24) & 0xFF), \
	((p1->color >> 24) & 0xFF));
	new_green = calc_new_col(percent, ((p0->color >> 16) & 0xFF), \
	((p1->color >> 16) & 0xFF));
	new_blue = calc_new_col(percent, ((p0->color >> 8) & 0xFF), \
	((p1->color >> 8) & 0xFF));
	return (combine_rgb(new_red, new_green, new_blue));
}

u_int32_t	get_color(char *str)
{
	u_int32_t	col;
	u_int32_t	str_bits;

	col = 0xFFFFFFFF;
	str_bits = 0;
	if (str != NULL)
	{
		col = a_to_hex(str + 2);
		col = col << 8;
		col = col | 0x000000FF;
	}
	return (col);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:58:14 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/31 11:03:47 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ternary(int statement, int true_out, int false_out)
{
	if (statement)
		return (true_out);
	return (false_out);
}

int	get_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

int	check_bounds(int x, int y)
{
	if (x < 0 || x >= WIDTH)
		return (-1);
	if (y < 0 || y >= HEIGHT)
		return (-1);
	return (1);
}

int	ft_atoi_prot(const char *str)
{
	int	x;
	int	sign;
	int	result;

	x = 0;
	sign = 1;
	result = 0;
	while (str[x] == 32 || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-')
	{
		sign = -1;
		x++;
	}
	else if (str[x] == '+')
		x++;
	while (str[x] && str[x] >= '0' && str[x] <= '9')
	{
		result = result * 10;
		result = result + (str[x] - '0');
		if (result < 0 && (result != INT_MIN || sign == 1))
			error();
		x++;
	}
	return (result * sign);
}

u_int32_t	a_to_hex(char *str)
{
	int			i;
	u_int32_t	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 16;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		else
			return (0);
		i++;
	}
	return (res);
}

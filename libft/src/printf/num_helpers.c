/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:04:18 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/14 11:17:28 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uns(va_list args)
{
	unsigned int	x;
	int				len;

	x = va_arg(args, unsigned int);
	ft_putnbr(x);
	if (x == 0)
		return (1);
	len = 0;
	while (x != 0)
	{
		len ++;
		x = x / 10;
	}
	return (len);
}

int	print_di(va_list args)
{
	int	x;
	int	len;

	x = va_arg(args, int);
	ft_putnbr(x);
	len = 0;
	if (x == 0)
		return (1);
	if (x < 0)
		len++;
	while (x != 0)
	{
		len++;
		x = x / 10;
	}
	return (len);
}

void	ft_putnbr(long n)
{
	char	c;
	char	r;

	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return ;
		n = (n * -1);
	}
	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		if (write(1, &c, 1) == -1)
			return ;
	}
	if (n > 9)
	{
		ft_putnbr((n / 10));
		r = (n % 10) + 48;
		if (write(1, &r, 1) == -1)
			return ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:02:30 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/15 14:41:14 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_low(va_list args)
{
	unsigned int	x;
	int				ret_val;

	x = va_arg(args, unsigned int);
	ret_val = lower_hex(x);
	return (ret_val);
}

int	print_hex_up(va_list args)
{
	unsigned int	x;
	int				ret_val;

	x = va_arg(args, unsigned int);
	ret_val = upper_hex(x);
	return (ret_val);
}

int	lower_hex(unsigned long num)
{
	int	ret_val;

	ret_val = 1;
	if (num < 10)
	{
		if (print_putchar('0' + num) == -1)
			return (-1);
	}
	if (num > 9 && num < 16)
	{
		if (print_putchar('a' + (num - 10)) == -1)
			return (-1);
	}
	if (num > 15)
	{
		lower_hex((num / 16));
		lower_hex((num % 16));
		while (num > 15)
		{
			ret_val++;
			num = num / 16;
		}
	}
	return (ret_val);
}

int	upper_hex(unsigned long num)
{
	int	ret_val;

	ret_val = 1;
	if (num < 10)
	{
		if (print_putchar('0' + num) == -1)
			return (-1);
	}
	if (num > 9 && num < 16)
	{
		if (print_putchar('A' + (num - 10)) == -1)
			return (-1);
	}
	if (num > 15)
	{
		upper_hex((num / 16));
		upper_hex((num % 16));
		while (num > 15)
		{
			ret_val++;
			num = num / 16;
		}
	}
	return (ret_val);
}

int	print_ptr(va_list args)
{
	void	*address;
	int		i;

	address = va_arg(args, void *);
	if (write(1, "0x", 2) == -1)
		return (-1);
	i = lower_hex((unsigned long)address) + 2;
	return (i);
}

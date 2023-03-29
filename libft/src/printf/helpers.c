/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:53:33 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/15 14:41:45 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putchar(int c)
{
	return (write(1, &c, 1));
}

int	print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	print_putstr(va_list args)
{
	int		x;
	char	*s;

	x = 0;
	s = va_arg(args, char *);
	if (!s)
		return (write(1, "(null)", 6));
	while (s[x])
	{
		if (write(1, &s[x], 1) == -1)
			return (-1);
		x++;
	}
	return (x);
}

int	print_per(va_list args)
{
	(void) args;
	if (print_putchar('%') == -1)
		return (-1);
	return (1);
}

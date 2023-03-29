/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:41:25 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/26 17:51:08 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	(*g_cfp[256])(va_list args) = {
['c'] = print_char,
['s'] = print_putstr,
['p'] = print_ptr,
['d'] = print_di,
['i'] = print_di,
['u'] = print_uns,
['x'] = print_hex_low,
['X'] = print_hex_up,
['%'] = print_per
};

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && g_cfp[(int)s[i + 1]])
		{
			len += g_cfp[(int)s[i + 1]](args);
			i++;
		}
		else
		{
			if (print_putchar(s[i]) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// #include <unistd.h>

// int	main()
// {
// 	ft_printf("\u2705");
// 	printf("\u2705");
// 	return (0);
// }
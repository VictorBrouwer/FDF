/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:06:00 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/08 16:38:32 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
int		print_hex_up(va_list args);
int		print_hex_low(va_list args);
int		print_putchar(int c);
int		print_char(va_list args);
int		print_putstr(va_list args);
int		print_ptr(va_list args);
int		print_di(va_list args);
void	ft_putnbr(long n);
int		lower_hex(unsigned long address);
int		upper_hex(unsigned long address);
int		print_uns(va_list args);
int		print_per(va_list args);

#endif
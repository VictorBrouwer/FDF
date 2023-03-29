/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 10:47:24 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/14 11:04:06 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	r;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = (n * -1);
	}
	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		r = (n % 10) + 48;
		write(fd, &r, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:04:35 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 17:45:03 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int		power10(int n);
static int		cnt_len(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = cnt_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		str[i] = '-';
		i++;
	}
	len = cnt_len(n);
	while (len > 0)
	{
		str[i++] = ('0' + (n / power10(len - 1)));
		n = n % power10(len - 1);
		len--;
	}
	return (str);
}

static int	power10(int n)
{
	int	x;

	x = 10;
	if (n == 0)
		return (1);
	while (n > 1)
	{
		x = x * 10;
		n--;
	}
	return (x);
}

static int	cnt_len(int n)
{
	int	x;

	x = 0;
	if (n < 0)
	{
		n = n * -1;
		x++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

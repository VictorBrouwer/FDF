/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 16:36:51 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/18 10:58:04 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*char_s1;
	unsigned char	*char_s2;

	char_s1 = (unsigned char *) s1;
	char_s2 = (unsigned char *) s2;
	x = 0;
	while (x < n)
	{
		if (char_s1[x] != char_s2[x])
			return (char_s1[x] - char_s2[x]);
		x++;
	}
	return (0);
}

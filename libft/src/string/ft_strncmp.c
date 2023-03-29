/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:25:24 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/18 10:47:30 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			x;
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *) s1;
	src2 = (unsigned char *) s2;
	x = 0;
	while ((src1[x] || src2[x]) && x < n)
	{
		if (src1[x] != src2[x])
			return ((unsigned char)src1[x] - (unsigned char)src2[x]);
		x++;
	}
	return (0);
}

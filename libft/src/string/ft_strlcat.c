/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:29:45 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/20 16:29:43 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	x = 0;
	y = dest_len;
	if (size < dest_len + 1)
		return ((src_len + size));
	if (size > 0 && dest_len < (size - 1))
	{
		while (src[x] && (dest_len + x) < (size - 1))
		{
			dest[y] = src[x];
			y++;
			x++;
		}
		dest[y] = '\0';
	}
	return ((dest_len + src_len));
}

// #include<stdio.h>
// #include<string.h>

// int	main(void)
// {
// 	char	src[2] = "e";
// 	char	src2[2] = "e";
// 	char	dest[20] = "yoy";
// 	char	dest2[20] = "yoy";
// 	printf("\nlib: %lu", strlcat(dest, src, 8));
// 	printf("\nown: %lu", ft_strlcat(dest2, src2, 8));
// 	printf("\n lib string: %s", dest);
// 	printf("\n own string: %s", dest2);
// 	return (0);
// }
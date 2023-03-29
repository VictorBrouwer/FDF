/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 16:56:36 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/17 18:41:27 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;
	int		needle_len;
	char	*ptr;

	x = 0;
	y = 0;
	needle_len = ft_strlen(needle);
	ptr = (char *) haystack;
	if (needle_len == 0 || needle == haystack)
		return (ptr);
	while (haystack[x] != '\0' && x < len)
	{
		y = 0;
		while (haystack[(x + y)] == needle[y] && (x + y) < len
			&& needle[y] != '\0')
			y++;
		if (needle[y] == '\0')
			return ((char *)&haystack[x]);
		x++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:15:51 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/11/11 16:14:18 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	x;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	x = 0;
	while (x < (count * size))
	{
		res[x] = '\0';
		x++;
	}
	return (res);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	x;
	char	*char_src;
	char	*char_dest;

	char_src = (char *) src;
	char_dest = (char *) dest;
	x = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n-- > 0)
			char_dest[n] = char_src[n];
	}
	else
	{
		while (x < n)
		{
			char_dest[x] = char_src[x];
			x++;
		}
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char			*p;
	size_t			i;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

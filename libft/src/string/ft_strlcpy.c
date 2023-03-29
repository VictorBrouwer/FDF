/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:24:22 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/20 12:19:59 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	i;

	res = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (res);
}

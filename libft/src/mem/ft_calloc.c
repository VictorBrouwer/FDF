/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 12:19:03 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/13 12:02:46 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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

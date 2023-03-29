/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 16:34:52 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/17 18:35:20 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *) s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) ptr[i] == (unsigned char) c)
			return (&ptr[i]);
		i++;
	}
	return (0);
}

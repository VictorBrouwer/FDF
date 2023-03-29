/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:21:06 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/12 09:49:26 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	*a = "hello";
// 	printf("%lu", strlen(a));
// 	printf("\n%d", ft_strlen(a));
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:12:09 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/21 16:42:16 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	x;
	char			*p;

	p = (char *) s;
	x = 0;
	while (p[x])
	{
		if (p[x] == (unsigned char) c)
			return (&p[x]);
		x++;
	}
	if (p[x] == (unsigned char) c)
		return (&p[x]);
	else
		return (NULL);
}

// int	main(void)
// {
// 	char	*a = "hello";
// 	printf("lib: %s", strchr(a, 'l'));
// 	printf("\nown: %s", ft_strchr(a, 'l'));
// 	return (0);
// }
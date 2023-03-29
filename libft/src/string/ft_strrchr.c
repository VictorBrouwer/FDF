/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:12:04 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/19 17:07:12 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	*p;

	p = (char *) s;
	x = ft_strlen(s);
	if (c == 0)
		return (&p[x]);
	while (x >= 0)
	{
		if (p[x] == (unsigned char) c)
			return (&p[x]);
		x--;
	}
	return (NULL);
}

// int main(void)
// {
// 	char	*a = "hello";
// 	printf("lib: %s", strrchr(a, 'l'));
// 	printf("\nown: %s", ft_strrchr(a, 'l'));
// 	return (0);
// }
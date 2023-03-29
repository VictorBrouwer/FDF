/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 08:57:56 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/13 15:11:11 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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

// int	main(void)
// {
// 	char	a[] = "helloooo";
// 	char	b[] = "martin";
// 	memmove(a, b, 6);

// 	printf("lib: %s", a);
// 	char	test[] = "helloooo";
// 	char	test2[] = "martin";
// 	ft_memmove(test, test2, 6);
// 	printf("\nown: %s", test);
// 	return (0);
// }
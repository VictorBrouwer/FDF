/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:50:01 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/20 12:09:53 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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

// int main () {
//    char str[50];
//    strcpy(str,"This is string.h library function");
//    puts(str);
//    memset(str,'A',7);
//    puts(str); 
//    return(0);
// }
// int	main(void)
// {
// 	char	*str = "yoyoyoyoyoyo";
// 	memset(str, 'A', 5);
// 	printf("test: %s", str);
// 	return (0);
// }
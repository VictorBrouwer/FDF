/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 15:06:19 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/10 13:34:35 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

// int main(void)
// {
//     int a;
//     int b;
//     a = 'A';
//     b = 'A';
//     printf("lib: %i", tolower(a));
//     printf("\nown: %i", ft_tolower(b));
//     return(0);
// }
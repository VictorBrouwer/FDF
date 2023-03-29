/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:49:15 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/10 13:34:42 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

// int main(void)
// {
//     int a;
//     int b;

//     a = 'b';
//     b = 'b';
//     printf("lib: %i", toupper(a));
//     printf("\nown: %i", ft_toupper(b));
//     return(0);
// }
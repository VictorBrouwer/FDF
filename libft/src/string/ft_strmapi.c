/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 14:19:07 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/17 12:28:59 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	res = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}

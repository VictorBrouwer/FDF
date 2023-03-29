/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 18:56:05 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/21 17:13:06 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (res = ft_strdup(s2));
	if (!s2)
		return (res = ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, (len_s1 + len_s2 + 1));
	ft_strlcat(res, s2, (len_s1 + len_s2 + 1));
	return (res);
}

// #include<stdio.h>
// int main()
// {
//   char  *s1 = NULL;
//   char  s2[] = "hihi";
//   printf("%s", ft_strjoin(s1, s2));
//   return 0;
// }
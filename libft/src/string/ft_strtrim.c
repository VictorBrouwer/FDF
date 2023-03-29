/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 11:15:34 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/31 10:52:06 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) != 0 && start < (size_t)ft_strlen(s1))
		start++;
	while (ft_strchr(set, s1[end]) != 0 && start < end)
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}

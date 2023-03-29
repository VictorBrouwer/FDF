/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:39:51 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/28 13:50:33 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_free_split(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
	return ;
}

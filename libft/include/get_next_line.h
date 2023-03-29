/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:18:19 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/26 17:43:34 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*get_next_line(int fd);
char	*obtain_line(char *buff, char *line);
int		find_char(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	update(char *buff);
void	*ft_memset(void *s, int c, size_t n);

#endif // GET_NEXT_LINE
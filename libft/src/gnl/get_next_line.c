/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:15:54 by vbrouwer          #+#    #+#             */
/*   Updated: 2022/12/09 11:15:38 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buff, 0) == -1)
		return (ft_memset(buff, 0, 1), NULL);
	line = ft_calloc(sizeof(char), 1);
	if (*buff)
		line = obtain_line(buff, line);
	while (line && find_char(line, '\n') == 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free (line), NULL);
		buff[bytes_read] = '\0';
		line = obtain_line(buff, line);
		if (bytes_read < BUFFER_SIZE)
			break ;
	}
	update(buff);
	if (!(*line))
		return (free(line), NULL);
	return (line);
}

void	update(char *buff)
{
	int	i;

	i = find_char(buff, '\n');
	if (!i)
		buff[0] = '\0';
	else
		ft_memmove(&buff[0], &buff[i], find_char(buff, '\0') - (i - 1));
	return ;
}

char	*obtain_line(char *buff, char *line)
{
	char	*result;
	int		i;
	int		j;
	int		buf_len;
	int		line_len;

	line_len = find_char(line, '\0');
	buf_len = find_char(buff, '\n');
	if (buf_len == 0)
		buf_len = find_char(buff, '\0');
	result = ft_calloc(sizeof(char), buf_len + line_len + 1);
	if (!result)
		return (free(line), NULL);
	i = 0;
	while (i < line_len)
	{
		result[i] = line[i];
		i++;
	}
	j = 0;
	while (j < buf_len)
		result[i++] = buff[j++];
	free (line);
	return (result);
}

int	find_char(char *s, char c)
{
	int	i;

	i = 0;
	if (c == '\n')
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (i + 1);
			i++;
		}
		return (0);
	}
	else
		while (s[i])
			i++;
	return (i);
}

// #include <stdio.h>

// void	func(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("1char.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	while (s != NULL)
// 	{
// 		printf("\nline: %s", s);
// 		free(s);
// 		s = get_next_line(fd);
// 	}
// 	printf("\nline: %s", s);
// 	free(s);
// 	close(fd);
// 	return ;
// }

// int	main(void)
// {
// 	func();
// 	return (1);
// }
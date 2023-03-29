/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 11:39:21 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/20 13:39:54 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splitcount(char const *s, char c);
static void	ft_free(char **res);
static char	**fill_arr(char const *s, char c, char	**res, int cnt);

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**res;

	if (!s)
		return (0);
	cnt = splitcount(s, c);
	res = malloc((cnt + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[cnt] = 0;
	res = fill_arr(s, c, res, cnt);
	return (res);
}

static char	**fill_arr(char const *s, char c, char	**res, int cnt)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i] && j < cnt)
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			start = i;
		while (s[i] != c && s[i])
			i++;
		if (i > start)
		{
			res[j] = ft_substr(s, start, (i - start));
			if (!res[j])
				return (ft_free(res), NULL);
			j++;
		}
	}
	return (res);
}

static void	ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free (res);
}

static int	splitcount(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			cnt++;
		while (c != *s && *s != '\0')
			s++;
	}
	return (cnt);
}

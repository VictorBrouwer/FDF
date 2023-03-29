/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrouwer <vbrouwer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:35:19 by vbrouwer          #+#    #+#             */
/*   Updated: 2023/03/26 19:28:09 by vbrouwer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>

# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

int		ft_printf(const char *s, ...);
int		print_hex_up(va_list args);
int		print_hex_low(va_list args);
int		print_putchar(int c);
int		print_char(va_list args);
int		print_putstr(va_list args);
int		print_ptr(va_list args);
int		print_di(va_list args);
void	ft_putnbr(long n);
int		lower_hex(unsigned long address);
int		upper_hex(unsigned long address);
int		print_uns(va_list args);
int		print_per(va_list args);

char	*get_next_line(int fd);
char	*obtain_line(char *buff, char *line);
int		find_char(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	update(char *buff);
void	*ft_memset(void *s, int c, size_t n);

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
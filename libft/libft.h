/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaggard <ohaggard@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:00:45 by vgocalv           #+#    #+#             */
/*   Updated: 2021/10/04 14:00:45 by vgocalv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include "get_next_line.h"
# include "ft_printf.h"

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *arr);
void	*ft_memset(void *memptr, int val, size_t num);
void	ft_bzero(void *memptr, size_t num);
void	*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void	*ft_memmove(void *destptr, const void *srcptr, size_t num);
size_t	ft_strlcpy(char *dst, const char *src, size_t maxlen);
size_t	ft_strlcat(char *dst, const char *src, size_t maxlen);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
char	*ft_strchr(const char *string, int symbol);
char	*ft_strrchr(const char *string, int symbol);
int		ft_strncmp(const char *string1, const char *string2, size_t num);
void	*ft_memchr(const void *memptr, int val, size_t num);
int		ft_memcmp(const void *memptr1, const void *memptr2, size_t num);
char	*ft_strnstr(const char *src1, const char *src2, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t arr_size, size_t cell_size);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
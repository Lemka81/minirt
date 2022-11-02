/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaggard <ohaggard@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:36:00 by ohaggard          #+#    #+#             */
/*   Updated: 2021/11/04 15:36:00 by ohaggard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*skip_spaces(char *s, char c)
{
	if (*s == '\0')
		return (s);
	while (*s == c)
		s++;
	return (s);
}

static int	skip_and_add(char **s, char **str, char c)
{
	int		size;
	char	*temp;

	size = 0;
	while ((*s)[size] != c && (*s)[size] != '\0')
		size++;
	*str = malloc(size + 1);
	if (!*str)
		return (0);
	temp = *str;
	while (**s != c && **s)
		*temp++ = *(*s)++;
	*temp = '\0';
	return (1);
}

static int	get_words_cnt(char *s, char c)
{
	int	words;

	words = 0;
	while (1)
	{
		if (*s == c)
			s = skip_spaces(s, c);
		if (*s)
		{
			words++;
			s++;
			while (*s != c && *s)
				s++;
		}
		else
			return (words);
	}
}

char	**ft_split(char const *s, char c)
{
	int		words_cnt;
	char	*str1;
	char	**str2;
	char	**out;

	words_cnt = get_words_cnt((char *)s, c);
	out = malloc(sizeof(char *) * (words_cnt + 1));
	if (!out)
		return (0);
	str2 = out;
	str1 = (char *)s;
	while (1)
	{
		str1 = skip_spaces(str1, c);
		if (*str1)
		{
			if (!skip_and_add(&str1, str2, c))
				return (0);
			str2++;
		}
		else
			break ;
	}
	out[words_cnt] = NULL;
	return (out);
}

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

static int	has_met(const char ch, const char *set)
{
	while (*set)
		if (*set++ == ch)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	cnt;
	char	*str1;
	char	*str2;
	char	*out;

	cnt = ft_strlen((char *)s1);
	str1 = (char *)s1 + cnt - 1;
	while (cnt && has_met(*str1--, set))
		cnt--;
	str1 = (char *)s1;
	while (cnt && has_met(*str1, set))
	{
		cnt--;
		str1++;
	}
	out = malloc(cnt + 1);
	if (!out)
		return (0);
	out[cnt] = '\0';
	str2 = out;
	while (cnt--)
		*str2++ = *str1++;
	return (out);
}

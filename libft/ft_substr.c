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

char	*ft_substr(char const *s, unsigned int start,
				size_t len)
{
	char	*out;
	size_t	size;

	size = ft_strlen((char *)s) + 1;
	if (size <= start + 1)
	{
		out = (char *)malloc(1);
		if (!out)
			return (0);
		*out = '\0';
		return (out);
	}
	s += start;
	len++;
	if (size > len)
		size = len;
	out = (char *)malloc(size);
	if (!out)
		return (0);
	ft_memcpy(out, s, size - 1);
	out[size - 1] = '\0';
	return (out);
}

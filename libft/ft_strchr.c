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

char	*ft_strchr(const char *string, int symbol)
{
	char	*out;

	out = (char *)string;
	symbol = (unsigned char)symbol;
	if (symbol == '\0')
	{
		while (*out != '\0')
			out++;
		return (out);
	}
	else
		while (*out != '\0')
			if (*out++ == symbol)
				return (--out);
	return (0);
}

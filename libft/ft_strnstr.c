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

char	*ft_strnstr(const char *src1, const char *src2, size_t len)
{
	size_t	i;
	size_t	src2_len;

	src2_len = ft_strlen((char *)src2);
	if (src2_len == 0)
		return ((char *)src1);
	i = 0;
	while (i <= len - src2_len && *src1 != 0)
	{
		if (!ft_strncmp(src1, src2, src2_len))
		{
			if (len)
				return ((char *)src1);
			else
				return (0);
		}
		src1++;
		i++;
	}
	return (0);
}

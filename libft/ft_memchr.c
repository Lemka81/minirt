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

void	*ft_memchr(const void *memptr, int val, size_t num)
{
	unsigned char	*arr;
	unsigned char	ch;

	ch = (unsigned char)val;
	arr = (unsigned char *)memptr;
	while (num > 0)
	{
		if (*arr == ch)
			return ((void *)arr);
		arr++;
		num--;
	}
	return (0);
}

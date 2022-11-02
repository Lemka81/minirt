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

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	char	*src;
	char	*dst;

	if (destptr < srcptr)
	{
		dst = (char *)destptr;
		src = (char *)srcptr;
		while (num--)
			*dst++ = *src++;
	}
	else if (destptr > srcptr)
	{
		dst = (char *)destptr + num;
		src = (char *)srcptr + num;
		while (num--)
			*--dst = *--src;
	}
	return (destptr);
}

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

int	ft_strncmp(const char *arr1, const char *arr2, size_t num)
{
	while (num != 0)
	{
		if (*arr1 != *arr2 || *arr1 == 0)
			return (*(unsigned char *)arr1 - *(unsigned char *)arr2);
		arr1++;
		arr2++;
		num--;
	}
	return (0);
}

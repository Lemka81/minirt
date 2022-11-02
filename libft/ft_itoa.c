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

static long long	ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	by_some_reason_its_part_of_ft_itoa(char **out, int *size,
												int n, int num)
{
	*size = 1;
	while (num)
	{
		num /= 10;
		(*size)++;
	}
	if (!n)
		(*size)++;
	if (n < 0)
	{
		*out = malloc(++(*size));
		if (!*out)
			return (0);
		**out = '-';
	}
	else
	{
		*out = malloc((*size));
		if (!*out)
			return (0);
	}
	(*out)[(*size) - 1] = '\0';
	(*size) -= 2;
	return (1);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*out;
	long long	temp;

	if (!by_some_reason_its_part_of_ft_itoa(&out, &size, n, n))
		return (0);
	if (!n)
	{
		out[0] = '0';
		return (out);
	}
	temp = ft_abs(n);
	while (temp)
	{
		out[size--] = temp % 10 + '0';
		temp /= 10;
	}
	return (out);
}

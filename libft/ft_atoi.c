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

unsigned long long	part_of_atoi(const char *str, unsigned long long num,
									char sign)
{
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str++ - '0';
		if (num > 9223372036854775807)
		{
			if (sign == 0)
				return (-1);
			else
				return (0);
		}
	}
	if (sign == 1)
		return ((int)num * -1);
	else
		return ((int)num);
}

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	char				sign;

	num = 0;
	sign = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (part_of_atoi(str, num, sign));
}

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
#include <unistd.h>

static unsigned int	ft_abs(int n, int fd)
{
	char	minus;

	minus = '-';
	if (n < 0)
	{
		write(fd, &minus, 1);
		return (-n);
	}
	return (n);
}

static void	add_in_file(int fd, unsigned int num)
{
	char	temp;

	if (num > 9)
		add_in_file(fd, num / 10);
	temp = num % 10 + '0';
	write(fd, &temp, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	add_in_file(fd, ft_abs(n, fd));
}

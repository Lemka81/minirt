/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaggard <ohaggard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:42:13 by ohaggard          #+#    #+#             */
/*   Updated: 2022/01/21 16:42:13 by ohaggard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num_x(unsigned int num)
{
	if (num > 15)
		print_num_x(num / 16);
	if (num % 16 < 10)
		num = num % 16 + '0';
	else
		num = num % 16 + 'a' - 10;
	write(1, &num, 1);
}

void	print_num_ux(unsigned int num)
{
	if (num > 15)
		print_num_ux(num / 16);
	if (num % 16 < 10)
		num = num % 16 + '0';
	else
		num = num % 16 + 'A' - 10;
	write(1, &num, 1);
}

void	print_num_u(long num)
{
	if (num > 9)
		print_num_u(num / 10);
	num = num % 10 + '0';
	write(1, &num, 1);
}

void	print_num_p(unsigned long num)
{
	ft_putstr_fd("0x", 1);
	internal_print_p(num);
}

void	internal_print_p(unsigned long num)
{
	if (num > 15)
		print_num_p(num / 16);
	if (num % 16 < 10)
		num = num % 16 + '0';
	else
		num = num % 16 + 'a' - 10;
	write(1, &num, 1);
}

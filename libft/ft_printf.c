/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaggard <ohaggard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:42:13 by ohaggard          #+#    #+#             */
/*   Updated: 2022/01/21 16:42:13 by ohaggard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_var(char ch, va_list *vlist)
{
	if (ch == '\0')
		return (0);
	else if (ch == 'c')
		ft_putchar_fd(va_arg(*vlist, int), 1);
	else if (ch == 's')
		ft_putstr_fd(va_arg(*vlist, char *), 1);
	else if (ch == 'd' || ch == 'i')
		ft_putnbr_fd(va_arg(*vlist, int), 1);
	else if (ch == 'p')
		print_num_p(va_arg(*vlist, int));
	else if (ch == '%')
		ft_putchar_fd('%', 1);
	else if (ch == 'u')
		print_num_u(va_arg(*vlist, unsigned int));
	else if (ch == 'x')
		print_num_x(va_arg(*vlist, int));
	else if (ch == 'X')
		print_num_ux(va_arg(*vlist, int));
	else
		return (0);
	return (2);
}

int	ft_printf(const char *string, ...)
{
	int		output_size;
	char	*str;
	va_list	vlist;

	if (!string)
		return (0);
	output_size = 0;
	str = (char *)string;
	va_start(vlist, string);
	while (*str)
	{
		if (*str == '%')
		{
			output_size += get_var(*(++str), &vlist);
			str++;
			continue ;
		}
		ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(vlist);
	return (output_size);
}

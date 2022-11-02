/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaggard <ohaggard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:42:13 by ohaggard          #+#    #+#             */
/*   Updated: 2022/01/21 16:42:13 by ohaggard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include "string.h"
# include "unistd.h"
# include "libft.h"

int		get_var(char ch, va_list *vlist);
int		ft_printf(const char *string, ...);
void	print_num_u(long num);
void	print_num_x(unsigned int num);
void	print_num_ux(unsigned int num);
void	print_num_p(unsigned long num);
void	internal_print_p(unsigned long num);

#endif

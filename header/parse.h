/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cojacque <cojacque@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:11:05 by cojacque          #+#    #+#             */
/*   Updated: 2022/11/03 18:16:16 by cojacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "../header/minirt.h"

t_color	split_rgb(char *rgb, t_store *st);
int		ft_strcmp(char *s1, char *s2);
void	ft_error(char *msg);
double	ft_atof(char *str);

#endif